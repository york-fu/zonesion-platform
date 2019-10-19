/*********************************************************************************************
* �ļ���Grating.c
* ���ߣ�Lixm 2017.10.17
* ˵���������դ��������
* �޸ģ�
* ע�ͣ�
*********************************************************************************************/

/*********************************************************************************************
* ͷ�ļ�
*********************************************************************************************/
#include "Grating.h"

/*********************************************************************************************
* ���ƣ�grating_init()
* ���ܣ������դ��������ʼ��
* ��������
* ���أ���
* �޸ģ�
* ע�ͣ�
*********************************************************************************************/
void grating_init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;                          //����һ��GPIO_InitTypeDef���͵Ľṹ��
  RCC_AHB1PeriphClockCmd(RASTER_RCC, ENABLE);                   //���������դ��ص�GPIO����ʱ��
  
  GPIO_InitStructure.GPIO_Pin = RASTER_PIN;                     //ѡ��Ҫ���Ƶ�GPIO����
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;                //�������ŵ��������Ϊ����
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;                  //��������ģʽΪ����ģʽ
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;                //��������Ϊ����ģʽ
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;              //������������Ϊ2MHz
  
  GPIO_Init(RASTER_GPIO, &GPIO_InitStructure);                  //��ʼ��GPIO����
}

/*********************************************************************************************
* ���ƣ�unsigned char get_grating_status(void)
* ���ܣ���ȡ�����դ������״̬
* ��������
* ���أ���
* �޸ģ�
* ע�ͣ�
*********************************************************************************************/
unsigned char get_grating_status(void)
{   
  if(GPIO_ReadInputDataBit(RASTER_GPIO, RASTER_PIN))            //�������դ��״̬��Ϣ
    return 1;
  else
    return 0;
}