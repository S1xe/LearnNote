###JSON Tutorial


This tutorial explains how to use JSONsyntax for the storage and exchange of information.

This tutorial JSON explained by multipleexamples, how to use JSON to create web services that return data in JSONformat as well as collect information JSON web services from third parties.

JSON can be used with HTTP Request, AJAX,PHP and JAVAVASCRIPT.

##### 1.- JSON Introduction 

JSON means JavaScript Open Notation. 

JSON is an alternative to XML format. 

JSON is a format for storing and exchangingdata. 

JSON is self-descriptive and easy to use. 

JSON is just text so it can be used fromany programming language. 

JSON is faster to read and write XMLformat. 

JSON can be used with HTTPRequest. 

JSON can be used with AJAX. 


**JSON example** 


```json
{"contacts":[

{"firstName":"Adam","lastName":"Smith"},

{"firstName":"Anne","lastName":"Davis"},

{"firstName":"Bruce","lastName":"Harris"},

{"firstName":"David","lastName":"Lee"}

]}
```

Example JSON object handling withjavascript
```html

<h2>JSON with JavaScript</h2>

<p id="data"></p>

<script>

var text ='{"firstName":"Adam","lastName":"Smith","age":"30"}';

var obj = JSON.parse(text);

document.getElementById("data").innerHTML= obj.firstName + "<br/>" + obj.lastName +"<br/>" + obj.age; </script>
```


#####2.- JSON Syntax

Data in JSON 

The JSON data is stored in name/valuepairs. 

*Example JSON data*

```"firstName":"Adam"```

*JSON object*

The data is separated by commas. 

Curly braces hold objects. 

Example JSON object 

```{"firstName":"Adam","lastName":"Smith"}```

*JSON Array*

Square brackets hold arrays.

Example JSON array 
```json

{"contacts":[

{"firstName":"Adam","lastName":"Smith"},

{"firstName":"Anne","lastName":"Davis"},

{"firstName":"Bruce","lastName":"Harris"},

{"firstName":"David","lastName":"Lee"}

]}
```
In this example, the <>JSON object"contacts" contains 4 JSON objects with their corresponding data. 

*JSON files*

The JSON file has the extension name"json". 

Example filename with JSON data 

data.json

The MIME type for JSON text is"application/json".


#####3.- JSON JAVASCRIPT

It is very easy to use JAVASCRIPT to accessthe values in a JSON object. 

For example, given the following objectJSON 

```json
{"contacts":[

{"firstName":"Adam","lastName":"Smith"},

{"firstName":"Anne","lastName":"Davis"},

{"firstName":"Bruce","lastName":"Harris"},

{"firstName":"David","lastName":"Lee"}

]}
```


We convert the JSON object in an JAVASCRIPTobject.

```javascript
var obj = JSON.parse(contacts);
```

If we enter the field "firstname"the first element:


``obj.contacts[0].firstName```

The result is:

```Adam```

We used the value 0 to select the first valueof the array. We will use the value 1 for the second element, and so on.


#####4.- JSON HTTP REQUEST

JSON is often used to collect data from aweb service and display the recovered data to a web page. 

Example JSON HTTP REQUEST

If we have the following file"data.txt" in our server 

File "data.json" 

```json
[
{"firstName":"Adam","lastName":"Smith"},
{"firstName":"Anne","lastName":"Davis"},
{"firstName":"Bruce","lastName":"Harris"},
{"firstName":"David","lastName":"Lee"}
]
```

HTML file that contains the JSON data forprevious file and displays its data on the same HTML page. 

HTML page "result.html"
```html 


<!DOCTYPE html>
<html>
<body>
<divid="divdata"></div>
<script>
var xmlhttp = new XMLHttpRequest();
var url = "data.json";
function myTransform(arr)
{
  var out = "";
  var i;
  for(i = 0; i < arr.length; i++)
   {
      out += arr[i].firstName + arr[i].lastName + '<br/>';
   }
  document.getElementById("divdata").innerHTML = out;
}

xmlhttp.onreadystatechange =function()  {
   if (xmlhttp.readyState == 4 && xmlhttp.status == 200)
    {
      var myData = JSON.parse(xmlhttp.responseText); myTransform(myData);
    }
  }
xmlhttp.open("GET", url, true);xmlhttp.send();
</script>
</body>
</html>
```

The result of executing the above website"result.html" in the web browser will be: 

```html
Adam Smith
Anne Davis
Bruce Harris
David Lee
```

##### 5.- JSON web service example

 The web service "contacts.php"queries the database and generates data retrieved JSON data format.

 File "contacts.php" 

```php
<?php
 header("Access-Control-Allow-Origin:*");
header("Content-Type:application/json; charset=UTF-8");
$conBD = new mysqli("myServer","myUser", "myPassword", "Northwind");
resultBD = conBD->query("SELECTfirsName, lastName FROM Contacts");
$out = "[";
while (res = resultBD->fetch_array(MYSQLI_ASSOC))
{
   if($out != "[")
   {
      $out .= ",";
  };
  $out .= '{"firsName":"' . $res["firsName"] .'",';
  out .= '"lastName":"'. res["lastName"] .'"}';
}
$out .="]";
$conBD->close();
echo($out);
?>
```

The following web page "result.html"consumed the previous web service to display data from the database"Contacts".

File "result.html"

```html
<!DOCTYPE html>
<html>
<body>
<h1>Contacts</h1>
<divid="divdata"></div>
<script>
var xmlhttp = new XMLHttpRequest();
var url = "datos.txt";
function myTransform(arr)
{
var out = "";
var i;
var out = "<table>";
out +="<tr><th>FirstName</th>";
out +="<th>LastName</th></tr>";
for(i = 0; i < arr.length; i++)
{
  out += "<tr>";
  out += "<td>";
  out += arr[i].firstName + "</td><td>";
  out += arr[i].lastName + "</td>"; out +="</tr>";
}
out += "</table>”;
document.getElementById("divdata").innerHTML= out; 
}
xmlhttp.onreadystatechange = function()
{
   if(xmlhttp.readyState == 4 && xmlhttp.status == 200)
   {
      var myData = JSON.parse(xmlhttp.responseText); 
      myTransform(myData);
   }
}
xmlhttp.open("GET", url, true);
xmlhttp.send();
</script>
</body>
</html>
```


The response in the web browser will be: 

``` json webservices example result ```

The source code of the result will be:

```html
<!DOCTYPE html>
<html>
<body>
<h1>Contacts</h1>
<table>
<tr><th>FirsName</th><th>LastName</th></tr>
<tr><td>Adam</td><td>Smith</td></tr>
<tr><td>Anne</td><td>Davis</td></tr>
<tr><td>Bruce</td><td>Harris</td></tr>
<tr><td>David</td><td>Lee</td></tr>
</table>
</body>
</html>
```




