#include "AllocateStatistics.h"

struct AllocHeader {
    uint32_t size : 31;
    uint32_t is_array : 1;
    uint8_t data[];
};

AllocTracker alloc_tracker;
unsigned int total_memory_used = 0;

void* operator new(size_t size)  {
    AllocHeader *header = static_cast<AllocHeader *>(std::malloc(size + sizeof(AllocHeader)));
    if (!header) throw std::bad_alloc();
    header->size = size;
    header->is_array = false;
    if(alloc_tracker.IsEnabled())
        alloc_tracker.Allocate(size);
    return header->data;
}

void* operator new[] (size_t size)  {
    AllocHeader *header = static_cast<AllocHeader *>(std::malloc(size + sizeof(AllocHeader)));
    if (!header) throw std::bad_alloc();
    if(alloc_tracker.IsEnabled())
        alloc_tracker.AllocateArray(size);
    header->size = size;
    header->is_array = true;
    return header->data;
}

void perform_delete(void *data)
{
    AllocHeader *header = reinterpret_cast<AllocHeader *>(static_cast<uint8_t *>(data) - sizeof(AllocHeader));

    if(alloc_tracker.IsEnabled())
    {
        if(header->is_array)
            std::cout << "ERROR: delete called on an array!!!" << std::endl;
        if(header->is_array)
            alloc_tracker.DeallocateArray(header->size);
        else
            alloc_tracker.Deallocate(header->size);
    }

    std::free(header);
}

void operator delete (void* data)
{
    perform_delete(data);
}

void operator delete [] (void* data)
{
    perform_delete(data);
}

void operator delete (void* data, size_t)
{
    perform_delete(data);
}

void operator delete [] (void* data, size_t )
{
    perform_delete(data);
}