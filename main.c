  #include <stdio.h>
  #include <stdlib.h>
  /*static void LED_TEST_getTestData(SWITCH_STATE_t* initial_switch_state,LED_STATE_t* initial_led_state,LED_STATE_t* expected_led_state, unsigned char test_num)
  {
      FILE* f = fopen("switch.txt","r+");
      char str1[20];
      char str2[20];
      char str3[20];

      if(f)
      {
          unsigned char i = 0 ;

          for(i = 0; i <= test_num; i++)
          {
              memset(str1,0,20);
              memset(str2,0,20);
              memset(str3,0,20);
              fscanf(f, "%s\t%s\t%s\n",str1, str2, str3);
          }


          if(strcmp(str1,"LED_OFF") == 0)
          {
              *initial_led_state = LED_OFF;
          }
          else if (strcmp(str1,"LED_ON") == 0)
          {
              *initial_led_state = LED_ON;
          }
          else if(strcmp(str1,"LED_FLASH") == 0)
          {
              *initial_led_state = LED_FLASH;
          }
          else
          {
              printf("Incorrect test data\n");
              return;
          }

          if(strcmp(str2,"SW_PREPRESSED") == 0)
          {
              *initial_switch_state = SW_PREPRESSED;
          }
          else if (strcmp(str2,"SW_PRESSED") == 0)
          {
              *initial_switch_state = SW_PRESSED;
          }
          else if(strcmp(str2,"SW_PRERELEASED") == 0)
          {
              *initial_switch_state = SW_PRERELEASED;
          }
          else if(strcmp(str2,"SW_RELEASED") == 0)
          {
              *initial_switch_state = SW_RELEASED;
          }
          else
          {
              printf("Incorrect test data\n");
          }

          if(strcmp(str3,"LED_OFF") == 0)
          {
              *expected_led_state = LED_OFF;
          }
          else if (strcmp(str3,"LED_ON") == 0)
          {
              *expected_led_state = LED_ON;
          }
          else if(strcmp(str3,"LED_FLASH") == 0)
          {
              *expected_led_state = LED_FLASH;
          }
          else
          {
              printf("Incorrect test data\n");
              return;
          }

          fclose(f);
      }
      else
      {
          printf("Failed To open the file");
      }

  }
  */
  #include <string.h>
  #define SW_PREPRESSED 0
  #define SW_PRESSED 1
  #define SW_PRERELEASED 2
  #define SW_RELEASED 3
  typedef unsigned char uint8_t;
  typedef uint8_t SWITCH_STATE_t ;

    static void Switch_getTestData(SWITCH_STATE_t* initial_switch_state,
    uint8_t test_num)
    {
    FILE* Input_File_Ptr2File = fopen("switch.txt","r+");

    char str1[20];
    char str2[20];
    char str3[20];
    char str4[20];
    if(Input_File_Ptr2File){
    for(int i=0;i<test_num+2;i++){
    memset(str1,0,20);
    memset(str2,0,20);
    memset(str3,0,20);
    memset(str4,0,20);
    fscanf(Input_File_Ptr2File,"%s\n",str1);
    fscanf(Input_File_Ptr2File,"%s\n",str2);
    fscanf(Input_File_Ptr2File,"%s\n",str3);
    fscanf(Input_File_Ptr2File,"%s\n",str4);
    }

    /*Make Your Decisions*/
    if(strcmp(str2,"SW_PREPRESSED") == 0)
    {
        *initial_switch_state = SW_PREPRESSED;
    }
    else if (strcmp(str2,"SW_PRESSED") == 0)
    {
        *initial_switch_state = SW_PRESSED;
    }
    else if(strcmp(str2,"SW_PRERELEASED") == 0)
    {
        *initial_switch_state = SW_PRERELEASED;
    }
    else if(strcmp(str2,"SW_RELEASED") == 0)
    {
        *initial_switch_state = SW_RELEASED;
    }
    else
    {
        printf("Incorrect test data\n");
    }

    fclose(Input_File_Ptr2File);


    }else{  printf("Failed To open the file");}
    }

  int main(int argc, char const *argv[])
  {SWITCH_STATE_t x=SW_RELEASED;
   Switch_getTestData(&x,1);
   printf("%i\n",x );
    return 0;
  }