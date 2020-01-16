#ifndef __ALLOCATE_TRACKER_H__
#define __ALLOCATE_TRACKER_H__

#include <iostream>
#include <memory>
#include <vector>
#include <cmath>
#include <random>
#include <chrono>
#include <deque>
#include <fstream>
#include <sstream>

struct AllocTracker {
    bool tracker_enabled = true;

    size_t total_memory = 0;
    size_t total_allocations = 0;
    size_t total_allocations_array = 0;

    size_t peak_memory = 0;
    size_t peak_allocations = 0;
    size_t peak_allocations_array = 0;

    using timepoint_t = std::chrono::time_point<std::chrono::system_clock>;

    static void WriteDate(std::ostream &output, timepoint_t t, unsigned int total_memory)
    {
        std::time_t now_c = std::chrono::system_clock::to_time_t(t);
        struct tm *parts = std::localtime(&now_c);

        auto seconds = std::chrono::time_point_cast<std::chrono::seconds>(t);
        auto fraction = t - seconds;

        auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(fraction).count();

        output <<  "[ new Date(" << 1900 + parts->tm_year  << ", " << 1    + parts->tm_mon << ", " << parts->tm_mday << ", "
               << parts->tm_hour << ", " << parts->tm_min << ", " << parts->tm_sec << ", " << milliseconds << "), " << total_memory << "], " << std::endl;
    }

    struct LogEntry {
        size_t total_memory;
        timepoint_t t;

        LogEntry(size_t total_memory = 0, timepoint_t t = std::chrono::system_clock::now())
                : total_memory(total_memory), t(t) {
        }

        void Dump(std::ostream &output)
        {
            WriteDate(output, t, total_memory);
        }
    };

    static constexpr size_t max_log_entries = 100000;
    LogEntry log[max_log_entries];
    size_t log_index = 0;

    std::string DumpLog()
    {
        std::ostringstream output;
        for(size_t i = 0; i < log_index; ++i)
            log[i].Dump(output);
        WriteDate(output, log[log_index - 1].t +std::chrono::milliseconds(100), log[log_index - 1].total_memory);
        return output.str();
    }

    template<typename T>
    static inline std::string ToString(T d)
    {
        std::ostringstream output;
        output << d;
        return output.str();
    }

    static inline std::string ReplaceString(std::string subject, std::string const &search, std::string const &replace) {
        size_t pos = 0;
        while ((pos = subject.find(search, pos)) != std::string::npos) {
            subject.replace(pos, search.length(), replace);
            pos += replace.length();
        }
        return subject;
    }

    void StopTracking()
    {
        tracker_enabled = false;
    }

    bool IsEnabled() const { return tracker_enabled; }

    void WriteGraph() {
         std::ifstream input("graph.tpl");
        if (!input) {
            std::cout << "Graph template file not found!!" << std::endl;
            throw std::runtime_error("Graph template file not found!!");
        }

        std::string str((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());

        str = ReplaceString(str, "{{LOG}}", DumpLog());
        str = ReplaceString(str, "{{MAX_MEMORY}}", ToString(peak_memory));
        str = ReplaceString(str, "{{MAX_ALLOCATIONS}}", ToString(peak_allocations));
        str = ReplaceString(str, "{{EXIT_MEMORY}}", ToString(log[log_index - 1].total_memory));
        //str = ReplaceString(str, "{{EXIT_ALLOCATIONS}}", ToString(log[log_index - 1].));

        std::ofstream output("graph.html");
        output << str;
    }

    AllocTracker()
    { }

    void Dump()
    {
        std::cout << "Total memory: " << total_memory << ", total allocations: " << total_allocations << ", total array allocations: " << total_allocations_array << std::endl;
    }

    void DumpPeaks()
    {
        std::cout << "Peak memory: " << peak_memory << ", peak allocations: " << peak_allocations << ", peak array allocations: " << peak_allocations_array << std::endl;
    }

    void AllocateLogEntry(size_t total_memory)
    {
        timepoint_t t = std::chrono::system_clock::now();
        if(log_index == 0 || log[log_index].t != t) {
            log[log_index] = LogEntry(total_memory, t);
            log_index = std::min(max_log_entries - 1, log_index + 1);
        } else {
            log[log_index].total_memory = total_memory;
        }
    }

    void Allocate(size_t size) {
        //std::cout << "Allocate: " << size << std::endl;
        total_memory += size;
        peak_memory = std::max(total_memory, peak_memory);
        total_allocations += 1;
        peak_allocations = std::max(total_allocations, peak_allocations);

        AllocateLogEntry(total_memory);
        //Dump();
    }

    void AllocateArray(size_t size) {
       // std::cout << "Allocate array: " << size << std::endl;
        total_memory += size;
        peak_memory = std::max(total_memory, peak_memory);
        total_allocations_array += 1;
        peak_allocations_array = std::max(total_allocations_array, peak_allocations_array);

        AllocateLogEntry(total_memory);
        //Dump();
    }

    void Deallocate(size_t size) {
        //std::cout << "Deallocate: " << size << std::endl;
        total_memory -= size;
        total_allocations -= 1;

        AllocateLogEntry(total_memory);
        //Dump();
    }

    void DeallocateArray(size_t size) {
        //std::cout << "Deallocate array: " << size << std::endl;
        total_memory -= size;
        total_allocations_array -= 1;

        AllocateLogEntry(total_memory);
        //Dump();
    }
};

extern AllocTracker alloc_tracker;

#endif
