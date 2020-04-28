#include "system.h"
#include "cmd.h"

extern UART_HandleTypeDef huart1;
extern TIM_HandleTypeDef htim3;

void angle_formation(void);

extern uint8_t RxBuff[1];
uint8_t error_back[]={'E','R','R','O','R'};

int pass_flag;
int angle,angle_pass;
uint8_t get;

void Cmd_Init(void)
{
	pass_flag=0;
	angle=0;
}

void Cmd_control(void)
{
	if(pass_flag==0)
	{
		switch(RxBuff[0])
		{	
			case '0':get=0;angle_formation();break;
			case '1':get=1;angle_formation();break;
			case '2':get=2;angle_formation();break;
			case '3':get=3;angle_formation();break;
			case '4':get=4;angle_formation();break;
			case '5':get=5;angle_formation();break;
			case '6':get=6;angle_formation();break;
			case '7':get=7;angle_formation();break;
			case '8':get=8;angle_formation();break;
			case '9':get=9;angle_formation();break;
			case '*':
				angle_pass=angle;
				angle=0;
				pass_flag=1;
				break;
			default:
				HAL_UART_Transmit(&huart1,error_back,sizeof(error_back),1000);
				Cmd_Init();
				break;
		}
	}
	if(pass_flag)
	{
		int compare;
		compare=499*((float)angle_pass/300);
		
		pass_flag=0;
		
		if(angle_pass<=300)
		{
			TIM3->CCR3=compare;//ÓÃµÄCH3
		}
		else 
		{
			TIM3->CCR3=498;
		}
	}
}
void angle_formation(void)
{
	angle=angle*10+get;
}
