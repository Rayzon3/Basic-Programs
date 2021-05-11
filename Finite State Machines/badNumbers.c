#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
   START,
   AFTER_MINUS,
   AFTER_DOT,
   __VALID_END_STATE,
   SECOND_DIGIT_ONWARDS,
   MANTISSA,
   __LAST_STATE
} FSM_STATES;

typedef struct {
   FSM_STATES state;
   char *tokens;
   FSM_STATES next_state;
} FSM_STATE_INFO;

int run(FSM_STATES start_state, FSM_STATE_INFO *state_machine, char *cargo) {
   FSM_STATE_INFO *p = state_machine;
   FSM_STATES current_state = start_state;
   FSM_STATE_INFO *found;
   char *c = cargo;

   while(*c != 0){
      found = NULL;
      p = state_machine;

      while(p -> state != __LAST_STATE){
         if(p -> state == current_state){
            if(strchr(p -> tokens, *c) != NULL){
               found = p;
               break;
            }
         }
         p++;
      }
      if(found != NULL){
         current_state = p -> next_state;
         c++;
      }
      else{
         printf("%s is bod. \n", cargo);
         printf("Failed at %c !!\n", *c);
         return -1;
      }
   }

   if(current_state > __VALID_END_STATE){
      printf("%s is good. \n", cargo);
      return 1;
   }
   else{
      printf("%s is bad! \n", cargo);
      return -2;
   }
}

int main(int argc, char *argv[]){
   
   static FSM_STATE_INFO state_machine[] = {
      {START, "0123456789", SECOND_DIGIT_ONWARDS},
      {START, "-", AFTER_MINUS},
      {AFTER_MINUS, "0123456789", SECOND_DIGIT_ONWARDS},
      {SECOND_DIGIT_ONWARDS, "0123456789", SECOND_DIGIT_ONWARDS},
      {SECOND_DIGIT_ONWARDS, ".", AFTER_DOT},
      {AFTER_DOT, "0123456789", MANTISSA},
      {MANTISSA, "0123456789", MANTISSA},
      {__LAST_STATE, "", __LAST_STATE}
   };

   run(START, state_machine, "-0.12");

   return 0;
}