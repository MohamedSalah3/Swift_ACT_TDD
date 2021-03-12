#include "Switch_Fake.h"
  static void Switch_getTestData(SWITCH_STATE_t* initial_switch_state,uint8_t test_num)
  {
  FILE* Input_File_Ptr2File = fopen("../../switch.txt","r+");

  char str1[20];
  char str2[20];
  char str3[20];
  char str4[20];
  if(Input_File_Ptr2File){
  for(int i=0;i<3;i++){
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