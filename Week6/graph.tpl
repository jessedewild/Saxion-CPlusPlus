<html>
<script type="text/javascript" src="dygraph.min.js"></script>
<link rel="stylesheet" src="dygraph.css" />
<script type="text/javascript">
var name = "Temperature";
var description = "Temperature";
var unit = "C";
</script>
<body>

<h1>Memory profile</h1>

<body>
<div id="graphdiv" style="width:800px; height:420px;"></div>
<script type="text/javascript">
  g = new Dygraph(

    	// containing div
    	document.getElementById("graphdiv"),
   	[
		{{LOG}}
	],
	 );
</script>
</body>

<table>	
	<tr>
	<td>Maximum memory allocated: </td>
	<td>{{MAX_MEMORY}}</td>
	</tr>
	<tr>
	<td>Total allocations: </td>
	<td>{{MAX_ALLOCATIONS}}</td>
	</tr>
	<tr>
	<td>Memory allocated at exit: </td>
	<td>{{EXIT_MEMORY}}</td>
	</tr>
</table>

</body>
</html>
