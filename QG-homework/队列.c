#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"queue.h"
/**
 *  @name        : void InitAQueue(AQueue *Q)
 *	@description : ��ʼ������
 *	@param		 : ����ָ��Q
 *	@return		 : None
 *  @notice      : None
 */
void InitAQueue(AQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
}

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *	@description : ��ʼ������
 *	@param		 : ����ָ��Q
 *	@return		 : None
 *  @notice      : None
 */
void InitLQueue(LQueue *Q);
/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *	@description : ���ٶ���
 *	@param		 : ����ָ��Q
 *	@return		 : None
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q)
{
    free(Q->data);
    Q->front = 0;
    Q->rear = 0;
    Q->data_size = 0;
}
/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *	@description : ���ٶ���
 *	@param		 : ����ָ��Q
 *	@return		 : None
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q);

/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *	@description : �������Ƿ�����
 *	@param		 : ����ָ��Q
 *	@return		 : ��-TRUE; δ��-FLASE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q)
{
    return (Q->rear + 1) % MAXQUEUE == Q->front ? 1 : 0;
}
/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *	@description : �������Ƿ�Ϊ��
 *	@param		 : ����ָ��Q
 *	@return		 : ��-TRUE; δ��-FLASE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q)
{
    return Q->front == Q->rear ? 1 : 0;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *	@description : �������Ƿ�Ϊ��
 *	@param		 : ����ָ��Q
 *	@return		 : ��-TRUE; δ��-FLASE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q);

/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *	@description : �鿴��ͷԪ��
 *	@param		 : ����ָ��Q�����Ԫ��e
 *	@return		 : �ɹ�-TRUE; ʧ��-FLASE
 *  @notice      : �����Ƿ��
 */
Status GetHeadAQueue(AQueue *Q, void *e)
{
    if(Q->front == Q->rear) return FLASE;
    else
    {
        e = Q->data[Q->front];
        return TRUE;
    }
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *	@description : �鿴��ͷԪ��
 *	@param		 : ����ָ��Q�����Ԫ��e
 *	@return		 : �ɹ�-TRUE; ʧ��-FLASE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void *e);

/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *	@description : ȷ�����г���
 *	@param		 : ����ָ��Q
 *	@return		 : ���г���count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)
{
    return (Q->rear-Q->front+MAXQUEUE)%MAXQUEUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *	@description : ȷ�����г���
 *	@param		 : ����ָ��Q
 *	@return		 : ���г���count
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q);

/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *	@description : ��Ӳ���
 *	@param		 : ����ָ��Q,�������ָ��data
 *	@return		 : �ɹ�-TRUE; ʧ��-FLASE
 *  @notice      : �����Ƿ����˻�Ϊ��
 */
Status EnAQueue(AQueue *Q, void *data)
{
    if(IsFullAQueue(Q))
    {
        return FLASE;
    }
    Q->data[Q->rear] = data;
    Q->rear = (Q->rear + 1) % MAXQUEUE;
    return TRUE;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *	@description : ��Ӳ���
 *	@param		 : ����ָ��Q,�������ָ��data
 *	@return		 : �ɹ�-TRUE; ʧ��-FLASE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data);

/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *	@description : ���Ӳ���
 *	@param		 : ����ָ��Q
 *	@return		 : �ɹ�-TRUE; ʧ��-FLASE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q)
{
    if(IsEmptyAQueue(Q))
    {
        return FLASE;
    }
    printf("%d",Q->data[Q->front]);
    Q->front = (Q->front + 1) % MAXQUEUE;
    return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *	@description : ���Ӳ���
 *	@param		 : ����ָ��Q
 *	@return		 : �ɹ�-TRUE; ʧ��-FLASE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q);

/**
 *  @name        : void ClearAQueue(AQueue *Q)
 *	@description : ��ն���
 *	@param		 : ����ָ��Q
 *	@return		 : None
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q)
{
    Q->front = Q->rear = 0;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *	@description : ��ն���
 *	@param		 : ����ָ��Q
 *	@return		 : None
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q);

/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *	@description : ������������
 *	@param		 : ����ָ��Q����������ָ��foo
 *	@return		 : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
    int i = Q->front;
    if(IsEmptyAQueue(Q))
    {
        return FLASE;
    }
    while(i != Q->rear)
    {
       foo(Q->data[i]);
       i = (i + 1) % MAXQUEUE;
    }
    return TRUE;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *	@description : ������������
 *	@param		 : ����ָ��Q����������ָ��foo
 *	@return		 : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q));

/**
 *  @name        : void APrint(void *q)
 *	@description : ��������
 *	@param		 : ָ��q
 *	@return		 : None
 *  @notice      : None
 */
 void APrint(void *q)
 {
     int choice, c = 0, flag = 0;
     void *p = q;
     printf("���������Ԫ�ص�����\n");
     while(flag)
     {
         printf("\t1.�ַ���\n\t2.����\n\t3.������");
         scanf("%d", &c);
         switch(c)
        {
            case 1:printf("%c", *(char*)p); //�ַ���
                   flag=0;break;
            case 2:printf("%d", *(int*)p); //����
                   flag=0;break;
            case 3:printf("%f", *(float*)p); //������
                   flag=0;break;
            default:printf("�������\n");
        }
     }


 }

/**
 *  @name        : void LPrint(void *q)
 *	@description : ��������
 *	@param		 : ָ��q
 *	@return		 : None
 *  @notice      : None
 */
 void LPrint(void *q);
 void aQueue()
 {
     AQueue AQ;
     LQueue LQ;
     int c, head, num, ch, intt, fl, input;
     do
    {
        printf("\t1.��ʼ������\n");
        printf("\t2.���ٶ���\n");
        printf("\t3.�������Ƿ�����\n");
        printf("\t4.�������Ƿ�Ϊ��\n");
        printf("\t5.�鿴��ͷԪ��\n");
        printf("\t6.ȷ�����г���\n");
        printf("\t7.��Ӳ���\n");
        printf("\t8.���Ӳ���\n");
        printf("\t9.��ն���\n");
        printf("\t10.������������\n");
        printf("\t11.������һ��\n");
        printf("\t������һ������\n");
        printf("\t");
        scanf("%d",&c);
        system("cls");
    switch(c)
    {
        case 1: InitAQueue(&AQ);
                printf("��ʼ���ɹ�\n");
                break;
        case 2: DestoryAQueue(&AQ);
                printf("���ٳɹ�\n");
                break;
        case 3: if(IsFullAQueue(&AQ))printf("��������\n");
                else printf("����δ��\n");
                break;
        case 4: if(IsEmptyAQueue(&AQ))printf("����Ϊ��\n");
                else printf("���в�Ϊ��\n");
                break;
        case 5: if(GetHeadAQueue(&AQ,&head))
                {
                    APrint(&head);
                }
                else printf("��ȡʧ��\n");
                break;
        case 6: printf("���г���Ϊ:%d",LengthAQueue(&AQ));
                break;
        case 7: printf("���������Ԫ�ص�����\n");
                printf("\t1.�ַ���\n\t2.����\n\t3.������");
                scanf("%d", &num);
                switch(c)
                {
                    case 1:scanf("%c",&ch); //�ַ���
                           if(EnAQueue(&AQ,&ch))
                                printf("��ӳɹ�\n");
                            else
                                printf("���ʧ��\n");
                           break;
                    case 2:printf("%d",&intt); //����
                            if(EnAQueue(&AQ,&intt))
                                printf("��ӳɹ�\n");
                            else
                                printf("���ʧ��\n");
                           break;
                    case 3:printf("%f",&fl); //������
                           if(EnAQueue(&AQ,&fl))
                                printf("��ӳɹ�\n");
                            else
                                printf("���ʧ��\n");
                           break;
                    default:printf("�������\n");
                }
                EnAQueue(&AQ, &input);
                break;
        case 8: if(DeAQueue(&AQ))
                    printf("���ӳɹ�\n");
                else
                    printf("����ʧ��\n");
                break;
        case 9: ClearAQueue(&AQ);
                break;
        case 10: if(TraverseAQueue(&AQ,APrint))
                 printf("�����ɹ�\n");
                 else
                 printf("����ʧ��\n");
        case 11: break;
        default: printf("��������ֲ���ȷ\n");
                 break;
    }
    }while(c!=11);
 }
 void lQueue()
 {

 }
int main()
{
    int a = 0;

    do
    {
        printf("\n\n");
        printf("\t1.ѭ������\n");
        printf("\t2.��ʽ����\n");
        printf("\t3.�˳�\n");
        printf("\t������һ������\n");
        printf("\t");
        scanf("%d",&a);
        system("cls");
         switch(a)
    {
        case 1: aQueue();
                break;
        case 2:
                break;
        case 3: break;
        default: printf("��������ֲ���ȷ\n");
                 break;
    }
    }while(a != 3);
    return 0;
}
