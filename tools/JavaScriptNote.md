## JavaScript随记

[TOC]

### 修改时间

##### JS的Dom节点访问

> Time:2016/10/25

### JS的Dom节点访问

#### 原代码如下

```javascript
<script type="text/javascript">
		onload=function test(){
			var x=document.documentElement.childNodes;
			//console.log(x);
  			//作为记录body下的元素的文本字符串
			var cnodes=String("body元素下的子节点:\n");
			for(var i=0;i<x.length;i++)
			{
              	//通过子节点判断是否为body
				if(x[i].childNodes==document.getElementsByTagName("body")[0].childNodes)
				{
					//var y=document.getElementsByTagName("body")[0].children;
                    var y=x[i]; 
					console.log(y);
					for(var j=0;j<y.length;j++)
					{
						//console.log(y[j].nodeName);
                      	//将body下的子节点元素添加到字符串中
						//cnodes=cnodes.concat(y[j].nodeName+"\n");
						cnodes+=(y[j].nodeName+"\n");
					}
					break;
				}
			}
			window.alert(cnodes);
		}	
	</script>
```

##### 优点

代码简单,容易实现

##### 缺点

可重用性不高,可读性略差,且仅能用于body下的元素

#### 修改后的代码

```javascript
<script type="text/javascript">
		function test(elem){
			var x=document.documentElement.childNodes;
			//console.log(x);
			var cnodes=String(elem+"元素下的子节点:\n");
			for(var i=0;i<x.length;i++)
			{
				if(x[i].childNodes==document.getElementsByTagName(elem)[0].childNodes)
				{
					//var y=document.getElementsByTagName("body")[0].children;
					var y=x[i].children;
					console.log(y);
					for(var j=0;j<y.length;j++)
					{
						//console.log(y[j].nodeName);
						//cnodes=cnodes.concat(y[j].nodeName+"\n");
						cnodes+=(y[j].nodeName+"\n");
					}
					break;
				}
			}			
			window.alert(cnodes);
		}
	</script>
```

##### 调用

```html
<body onload="test('body')">
    <h1>DOM节点访问</h1>
    <h2>DOM节点访问</h2>
    <input type="text" onmousemove="test('body')" />
</body>
```

##### 优点

可以在一定程度上重用

##### 缺点

对于某些重复的元素并没有很有效的去获取,比如div,仍需改进

