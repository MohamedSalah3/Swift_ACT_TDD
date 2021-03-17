<h1>Speed Control Using TDD</h1>

<h2> Introduction</h2>

<h3> Who Am I ?</h3>
<p>

Hello , My name is Mohamed Ahmed Salah , Sprints Wave 8 Graduate ,Egyptian Russian University Mechatronics Department Graduate Since 2019 

<h3> Lets focus again !</h3>
<p>
Our Project today is Speed Control using Test driven Development As a better approach to build a project . to make it clear for you we will  first start Descripting The project Then We will Talk about The Code Written and The approach Taken while Developing This Project    
</p>
<h2> Project Description </h2>
<p>
We wanna Control a Motor speed so We will make a user to machine famous Interface 
</p>
<p>
Called Push Buttons :) ,we will use 3 pushbuttons Called Upswitch , DownSwitch  , P_Switch 
</p>
<h3>  Up switch </h3>
<p>
when Prepressed Will increment Motor Speed By one which means Decreasing Motor angle by one 
</p>

<h3> Down switch</h3>
<p>
when Prepressed Will do the opposite of Up switch functionality and Lastly 
</p>

<h3> P Switch </h3>
<p>
This Button Is special it makes User Changes speed By Pressing For a while AS it increments Motor angle By one Every 30 ms which decrements Motor speed while pressing it 
</p>

<h2> Project requirement's</h2>
<p>
As There is No Hardware used in this Project it is Required To take the Switch Actions not from The hardware but from Switch.txt which will act like a genral Purpose Input output  log . After This You should Process This Data In A module Called Switch Then Pass This information To Speed Control Module , Speed Control Module Will Manipulate The Input Data To send the required Angles to Motor module which will then write this data to a text file called Motor.txt
</p>
<h2> Project Implementation  </h2>
<p>
i made two folders one is source folder which contains all three modules 
Switch  , Speed Control , Motor .
</p>
<h3>  Switch Module </h3>
<p>
The Method Used here For Function Prototyping Was To Return Error Status 
Which is basically 
</p>

> ```c
> typedef uint8_t ERROR_STATUS;
> ```

>```c
>#define E_NOK        1
>```

>```c
>#define E_OK         0 
>```

>```c
>#define NULL_PTR    2
>```

>```c
>#define NOT_INIT    4
>```

>```c
>#define MULTIPLE_INIT 6
>```

>```c
>#define INVALID_PARM  8
>```

<p>
And with it i defied Multiple Macros to make it readable , By using this  method i will be sure that there is a feedback from the function of what  really happened .

So these are The functions used in this module 
>```c
>ERROR_STATUS  SWITCH_init(Switch_Cfg_str* Switch_used);
>```

>```c
>ERROR_STATUS SWITCH_update(Switch_Cfg_str*Switch_used,test_Cfg_str*Test_data);
>```
<p>
The most important Parts of this Module Are lies here When we make a structure to represent every button we have to make usable for both testing and production and actuallyit was so useful 
Members that was so useful while coding are Switch id , Switch status , push time and lastly Programming mode.
Switch id was used to make every button different from the others 
switch status used to know the status of buttons 
push time was exclusive for p switch 
and lastly programming mode used in init function to swap the used functions when production and when testing as we have used a pointer to function to do this trick .
</p>

>```c
> typedef struct Switch_Cfg_str{
>	uint8_t GPIO;
>	uint8_t pins;
>	uint8_t Switch_ID;
>	SWITCH_STATE_t Switch_status;
>	uint8_t Programming_Mode;
>	uint32_t Push_Time;
>	 uint8_t u8_Mult_init_detect;
>     }Switch_Cfg_str;    
>```

<p>
As You can see we swapped this functions in the init function using pointer to function 
</p>

>```c
>	SWITCH_STATE_t  SWITCH_getSwState_real(Switch_Cfg_str* Switch_used);
>```

>```c
>	SWITCH_STATE_t  SWITCH_getSwState_Fake(Switch_Cfg_str* Switch_used);
>```

>```c
>	uint32_t  SWITCH_getP_time_real(Switch_Cfg_str* Switch_used);
>```

>```c
>	uint32_t  SWITCH_getP_time_Fake(Switch_Cfg_str* Switch_used);
>```
<p>
These are the objects which was created
</p>
>   extern Switch_Cfg_str UpSwitch;

>   extern Switch_Cfg_str DownSwitch;

>   extern Switch_Cfg_str P_Switch;


<h3>  Speed Control Module</h3>
<p>
In This Module Basically What We are doing is to take Data out of object to inject it in another Object . 
so in this module we constructed a structure which will take the data from all push button structure and put it in a new structure 
the data we were most intrested in are Switches status and push time so we created this structure to handle this task .

> ```c
>    typedef struct speed_Cfg_str  {  
>    uint8_t Switch_ID[3];
> ```

<p>
So Whats really happening here is we used the switch id from switch module as an index to this array member of our struct to Update all three buttons in one object
</p>

> ```c
>   SWITCH_STATE_t Switch_status[3];
> ```

<p>
as you can see Push time is also here to take the value stored in push time member in the first Module(switch module)
</p>

>```c
>uint32_t Push_Time;
>```

<p>
And Motor Angle member which the Update function used to store its updated Angle on it 
</p>

>
> 	 ```c
> 	   MOTOR_ANGEL_t MOTOR_angel;
> 	   uint8_t Programming_Mode;
> 	  }speed_Cfg_str;
> 	   extern speed_Cfg_str SpeedSTR_update;
> 	 ```

<p>
 So these are The functions used in this module
 </p>


>```c
>ERROR_STATUS Speed_Control_init(void);
>```



>```c
>ERROR_STATUS Speed_Control_get_Switch_state(speed_Cfg_str* SpeedSTR_used);
>```



>```c
>	MOTOR_ANGEL_t Angel_update(speed_Cfg_str* SpeedSTR_used);
>```

<h3>  Motor Module</h3>
<p>
In This Module Basically What We are doing is to take Data out of object to Print it in a text file  . 
</p>

>```c
>  ERROR_STATUS MOTOR_init(void);
>```

>```c
>MOTOR_ANGEL_t MOTOR_getAngel(speed_Cfg_str* SpeedSTR_used);
>```

>```c
>void MOTOR_update(void);
>```

<h1> How To Run This Project  </h1>

