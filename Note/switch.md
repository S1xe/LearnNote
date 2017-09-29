```c++
switch(expression) statement
  
 //Normal
 switch(expr)
 {
   case 0:
    stmt0;
   case 1:
    stmt1;
   case 2:
    stmt2;
   default:
    stmtdefault;
 }


//Special
switch (expr)
{
	default:
		if (cond1)
		{
		case 1:
			stmt1;
		case 2:
			stmt2;
		}			
    	else			
        {				
          if (cond2)
			case 3:
				stmt3;
          else
            case 0:
              stmt0;
		}		
}


//Example
//Use to post a tree
bool Postorder::next ()
{
	switch (pc)
	{
      case START:
      while (true)
      if (!lchild())
      {
        pc = LEAF;
        return true;
        
        case LEAF:
        	while (true)
          	if (sibling())
            	break;
            else if (parent())
            {
              pc = INNER;
              return true; 
              
            case INNER: ;
            }
            else
            {
              pc = DONE;
              case DONE:
              return false;
     		}
      }
	}
}
```

