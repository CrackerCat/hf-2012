//////////////////////////////////////////////////////////////////
// iocommon.h�ļ�

#ifndef __IOCOMMON__H
#define __IOCOMMON__H


//////////////////////////////////////////////////////////
// ����IO��������


typedef struct _PTUSERIO_OID_DATA 
{
    ULONG           Oid;
    ULONG           Length;
    UCHAR           Data[1];
}PTUSERIO_OID_DATA, *PPTUSERIO_OID_DATA;


// ����״̬
typedef struct _PassthruStatistics 
{
   ULONG    nMPSendPktsCt;      // ͨ��MPSendPackets�ķ��
   ULONG    nMPSendPktsDropped; // ��MPSendPackets�ж����ķ��
   ULONG    nPTRcvCt;           // ͨ��PTReceive�ķ��
   ULONG    nPTRcvDropped;      // ��PTReceive�ж����ķ��
   ULONG    nPTRcvPktCt;        // ͨ��PTReceivePacket�ķ��
   ULONG    nPTRcvPktDropped;   // ��PTReceivePacket�ж����ķ��
}PassthruStatistics, *PPassthruStatistics;

// ���˹���
typedef struct _PassthruFilter
{
	USHORT protocol;		// ʹ�õ�Э��

	ULONG sourceIP;			// ԴIP��ַ
	ULONG sourceMask;		// Դ��ַ������     ����ʹ����������Ϊ���ܹ�����һ��IP��ַ��Χ

	ULONG destinationIP;	// Ŀ��IP��ַ
	ULONG destinationMask;	// Ŀ�ĵ�ַ������

	USHORT sourcePort;		// Դ�˿ں�
	USHORT destinationPort;	// Ŀ�Ķ˿ں�
	
	BOOLEAN bDrop;			// �Ƿ����˷��

}PassthruFilter, *PPassthruFilter;


////////////////////////////////////////////////////////////
// ����IO���ƴ���

#define FSCTL_PTUSERIO_BASE      FILE_DEVICE_NETWORK

// ö�ٰ󶨵�������
#define IOCTL_PTUSERIO_ENUMERATE   \
            CTL_CODE(FSCTL_PTUSERIO_BASE, 0x201, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
 
// ��һ��������
#define IOCTL_PTUSERIO_OPEN_ADAPTER   \
            CTL_CODE(FSCTL_PTUSERIO_BASE, 0x202, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_PTUSERIO_SET_OID	\
		CTL_CODE(FSCTL_PTUSERIO_BASE, 0x203, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#define IOCTL_PTUSERIO_QUERY_OID  \
		CTL_CODE(FSCTL_PTUSERIO_BASE, 0x204, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
    

    
// ��ȡ����״̬
#define IOCTL_PTUSERIO_QUERY_STATISTICS   \
			CTL_CODE(FSCTL_PTUSERIO_BASE, \
				0x205, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
 
// ��������״̬
#define IOCTL_PTUSERIO_RESET_STATISTICS   \
			CTL_CODE(FSCTL_PTUSERIO_BASE, \
				0x206, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
 
// ����һ�����˹���
#define IOCTL_PTUSERIO_ADD_FILTER			\
			CTL_CODE(FSCTL_PTUSERIO_BASE,	\
				0x207, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

// ������˹���
#define IOCTL_PTUSERIO_CLEAR_FILTER			\
			CTL_CODE(FSCTL_PTUSERIO_BASE,	\
				0x208, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)


#endif // __IOCOMMON__H





