/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may
 * *    be used to endorse or promote products derived from this software
 * *    without specific prior written permission.
 *
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/******************************************************************************

                  ��Ȩ���� (C), 2001-2012, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : ScInterface.h
  �� �� ��   : ����
  ��    ��   : ��Ц��
  ��������   : 2012��4��3��
  ����޸�   :
  ��������   : SCģ���ṩ���ⲿģ��Ľӿ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2012��4��3��
    ��    ��   : w00184875
    �޸�����   : V7R1C51 ����������Ŀ����

******************************************************************************/

#ifndef __SCINTERFACE_H__
#define __SCINTERFACE_H__


/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/
#include "vos.h"
#include "UsimPsInterface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#pragma pack(4)


/*****************************************************************************
  1 ��Ϣͷ����
*****************************************************************************/


/*****************************************************************************
  2 �궨��
*****************************************************************************/
#define   SC_MAX_SUPPORT_CATEGORY   (3)   /* ֧�ֵ���������CATEGORY�������Ŀǰֻ֧������:network/network subset/SP */

#define   SC_MAX_CODE_LEN           (4)   /* �Ŷε���󳤶�(����Ϊ3��������Ϊ4����SPΪ4��ȡ����) */

#define   SC_CP_MAX_CODE_LEN        (6)   /* ��CPΪ5���ֽ� + 1�ֽڶ���*/

#define   SC_MAX_CODE_NUM           (20)  /* ���������Ŷ������� */

#define   SC_SIGNATURE_LEN          (32)  /* ǩ������ */

#if (FEATURE_ON == FEATURE_SC_SEC_UPDATE)

#define   SC_AUTH_PUB_KEY_LEN       (516) /* ������Ȩ��Կ����(AK���ļ�lenth) */

#define   SC_AUTH_PUB_KEY_TOTAL_LEN (SC_AUTH_PUB_KEY_LEN * 2) /* 2����Ȩ��Կ����(���ݼ�lenth) */

#define   SC_RSA_ENCRYPT_LEN        (256) /* ����RSA���ܺ�����ĳ��������汾����������ټ������°汾 */

#define   SC_CRYPTO_PWD_LEN         (32)  /* ��������ĳ���,pbkdf2���� */
#else

#define   SC_AUTH_PUB_KEY_LEN       (260) /* ������Ȩ��Կ����(AK���ļ�lenth) */

#define   SC_AUTH_PUB_KEY_TOTAL_LEN (SC_AUTH_PUB_KEY_LEN * 2) /* 2����Ȩ��Կ����(���ݼ�lenth) */

#define   SC_RSA_ENCRYPT_LEN        (128) /* ����RSA���ܺ�����ĳ��� */

#define   SC_CRYPTO_PWD_LEN         (16)  /* ��������ĳ���,AES_ECB���� */
#endif

#define   SC_PERS_PWD_LEN           (16)  /* CK/UK/DK��������ĳ��� */

#define   SC_PI_HEAD_FLAG           (0x5A5AA5A5)

#define   SC_PIN_PWD_LEN            (16)  /* PIN��������ĳ��� */

#define   SC_IV_LEN                 (4)  /* IV���� ע:IV����Ϊ16�ֽڣ���INT32�洢 */

#define   SC_CRYPTO_CBC_PIN_LEN     (16)  /* ��������ĳ���AES_CCB���� */

/*****************************************************************************
  3 ö�ٶ���
*****************************************************************************/
/*****************************************************************************
ö����    : SC_ERROR_CODE_ENUM
ö��˵��  : SCģ�������ö�ٶ���

  1.��    ��   : 2012��4��3��
    ��    ��   : w00184875
    �޸�����   : V7R1C51 ����������Ŀ����
*****************************************************************************/
enum SC_ERROR_CODE_ENUM
{
    SC_ERROR_CODE_NO_ERROR              = 0,        /*    �����ɹ� */
    SC_ERROR_CODE_OPEN_FILE_FAIL,                   /* 1  ���ļ�ʧ�� */
    SC_ERROR_CODE_READ_FILE_FAIL,                   /* 2  ��ȡ�ļ�ʧ�� */
    SC_ERROR_CODE_WRITE_FILE_FAIL,                  /* 3  д���ļ�ʧ�� */
    SC_ERROR_CODE_VERIFY_SIGNATURE_FAIL,            /* 4  ǩ��У��ʧ�� */
    SC_ERROR_CODE_DK_INCORRECT,                     /* 5  DK���벻��ȷ */
    SC_ERROR_CODE_UNLOCK_KEY_INCORRECT,             /* 6  CK/UK���벻��ȷ */
    SC_ERROR_CODE_UNLOCK_STATUS_ABNORMAL,           /* 7  ����/UNBLOCKʱ��״̬����ȷ */
    SC_ERROR_CODE_RSA_ENCRYPT_FAIL,                 /* 8  RSA����ʧ�� */
    SC_ERROR_CODE_RSA_DECRYPT_FAIL,                 /* 9  RSA����ʧ�� */
    SC_ERROR_CODE_VERIFY_PUB_KEY_SIGNATURE_FAIL,    /* 10 ��Ȩ��Կ��ժҪǩ��У��ʧ�� */
    SC_ERROR_CODE_GET_RAND_NUMBER_FAIL,             /* 11 ��ȡ�����ʧ��(crypto_rand) */
    SC_ERROR_CODE_IDENTIFY_FAIL,                    /* 12 ���߼�Ȩʧ�� */
    SC_ERROR_CODE_IDENTIFY_NOT_FINISH,              /* 13 ��δ��ɲ��߼�Ȩ */
    SC_ERROR_CODE_LOCK_CODE_INVALID,                /* 14 �����Ŷα���ȡֵ����ȷ */
    SC_ERROR_CODE_CREATE_KEY_FAIL,                  /* 15 ��Կ����ʧ��(create_crypto_key) */
    SC_ERROR_CODE_GENERATE_HASH_FAIL,               /* 16 ����HASHʧ��(crypto_hash) */
    SC_ERROR_CODE_HMAC_ENCRYPT_FAIL,                /* 17 hmac�㷨����������ǩ��ʧ��(crypto_encrypt) */
    SC_ERROR_CODE_PBKDF2_ENCRYPT_FAIL,              /* 18 PBKDF2�㷨����ʧ��(crypto_encrypt) */
    SC_ERROR_CODE_AES_ECB_ENCRYPT_FAIL,             /* 19 AES ECB�㷨����ʧ��(crypto_encrypt) */
    SC_ERROR_CODE_WRITE_HUK_FAIL,                   /* 20 HUKд����� */
    SC_ERROR_CODE_ALLOC_MEM_FAIL,                   /* 21 �����ڴ�ʧ�� */
    SC_ERROR_CODE_PARA_FAIL,                        /* 22 ����������� */
    SC_ERROR_CODE_WRITE_FILE_IMEI_FAIL,             /* 23 IMEI����д���ļ����� */
    SC_ERROR_CODE_CMP_IMEI_FAIL,                    /* 24 �Ƚ�IMEI�ַ���ʧ�� */
    SC_ERROR_CODE_MODEM_ID_FAIL,                    /* 25 ModemID ���� */
    SC_ERROR_CODE_NV_READ_FAIL,                     /* 26 NV��ʧ�� */
    SC_ERROR_CODE_NV_WRITE_FAIL,                    /* 27 NVдʧ�� */
    SC_ERROR_CODE_SCCONTENT_WRITE_FAIL,             /* 28 SC�ļ�д�뱸����ʧ�� */
    SC_ERROR_CODE_SCBACKUP_READ_FAIL,               /* 29 ��ȡSC������ʧ�� */
    SC_ERROR_CODE_MAGNUM_CMP_FAIL,                  /* 30 �Ƚ�SC���������ʧ�� */
    SC_ERROR_CODE_SCFILE_RESTORE_FAIL,              /* 31 SC�ļ�д��ʹ����ʧ�� */
    SC_ERROR_CODE_SC_NO_NEED_RESTORE,               /* 32 SC�ļ�����Ҫ�ָ� */
    SC_ERROR_CODE_CACHE_FILE_NOT_EXIT,              /* 33 �����в�����SC�ļ� */
    SC_ERROR_CODE_CACHE_FILE_LEN_ERR,               /* 34 ������SC�ļ����ݳ�����Ԥ�ڲ�һ�� */
    SC_ERROR_CODE_CACHE_FILE_ERR,                   /* 35 ������SC�ļ�������Ԥ�ڲ�һ�� */
    SC_ERROR_CODE_NW_UPDATE_FORBIDDEN,              /* 36 ������δ����*/
    SC_ERROR_CODE_NONEED_CHECK_SIMSLOT,             /* 37 ����Ҫ����濨ƥ�� */
    SC_ERROR_CODE_HMAC_CHECK_FAIL,                  /* 38 HMAC�����Լ��ʧ�� */
    SC_ERROR_CODE_AES_CBC_ENCRYPT_FAIL,             /* 39 AES CBC�㷨����ʧ�� */
    SC_ERROR_CODE_AES_CBC_DECCRYPT_FAIL,            /* 40 AES CBC�㷨����ʧ�� */

    SC_ERROR_CODE_OTHER_ERROR,                      /*    �������� */

    SC_ERROR_CODE_BUTT
};
typedef VOS_UINT32  SC_ERROR_CODE_ENUM_UINT32;

/*****************************************************************************
ö����    : SC_PERSONALIZATION_CATEGORY_ENUM
ö��˵��  : ����������category����

  1.��    ��   : 2012��4��3��
    ��    ��   : w00184875
    �޸�����   : V7R1C51 ����������Ŀ����
*****************************************************************************/
enum SC_PERSONALIZATION_CATEGORY_ENUM
{
    SC_PERSONALIZATION_CATEGORY_NETWORK                     = 0x00, /* category:���� */
    SC_PERSONALIZATION_CATEGORY_NETWORK_SUBSET              = 0x01, /* category:������ */
    SC_PERSONALIZATION_CATEGORY_SERVICE_PROVIDER            = 0x02, /* category:��SP */
    SC_PERSONALIZATION_CATEGORY_CORPORATE                   = 0x03, /* category:������ */
    SC_PERSONALIZATION_CATEGORY_SIM_USIM                    = 0x04, /* category:��(U)SIM�� */

    SC_PERSONALIZATION_CATEGORY_BUTT
};
typedef VOS_UINT8 SC_PERSONALIZATION_CATEGORY_ENUM_UINT8;

/*****************************************************************************
ö����    : SC_PERSONALIZATION_SUPPORT_LIST_ENUM
ö��˵��  : ��������֧����������

  1.��    ��   : 2016��4��3��
    ��    ��   : d00212987
    �޸�����   : ����������Ŀ����
*****************************************************************************/
enum SC_PERSONALIZATION_SUPPORT_CORPORATE_ENUM
{
    SC_PERSONALIZATION_NOT_SUPPORT_CORPORATE          = 0x00, /* ��֧�������� */
    SC_PERSONALIZATION_SUPPORT_CORPORATE              = 0x01, /* ֧�������� */

    SC_PERSONALIZATION_SUPPORT_CORPORATE_BUTT
};
typedef VOS_UINT8 SC_PERSONALIZATION_SUPPORT_CORPORATE_ENUM_UINT8;

/*****************************************************************************
ö����    : SC_PERSONALIZATION_SUPPORT_LIST_ENUM
ö��˵��  : ��������֧����������

  1.��    ��   : 2016��4��3��
    ��    ��   : d00212987
    �޸�����   : ����������Ŀ����
*****************************************************************************/
enum SC_PERSONALIZATION_SUPPORT_LIST_ENUM
{
    SC_PERSONALIZATION_SUPPORT_WHITELIST              = 0x00, /* ������ */
    SC_PERSONALIZATION_SUPPORT_BLACKLIST              = 0x01, /* ������ */

    SC_PERSONALIZATION_SUPPORT_BUTT
};
typedef VOS_UINT8 SC_PERSONALIZATION_SUPPORT_LIST_ENUM_UINT8;

/*****************************************************************************
 ö����    : SC_PERSONALIZATION_PLATFORM_ENUM_UINT32
 ö��˵��  : SC Modem����ʽö��

  1.��    ��   : 2016��01��06��
    ��    ��   : d00212987
    �޸�����   : SC���Ӷ�CDMA��ʽ֧������
*****************************************************************************/
enum SC_PERSONALIZATION_PLATFORM_ENUM
{
    SC_PERSONALIZATION_PLATFORM_G,   /* �ǵ���ģʽ�������� */

    SC_PERSONALIZATION_PLATFORM_C,   /* ����ģʽ�������� */

    SC_PERSONALIZATION_PLATFORM_BUT,
};
typedef VOS_UINT8 SC_PERSONALIZATION_PLATFORM_ENUM_UINT8;

/*****************************************************************************
ö����    : SC_PERSONALIZATION_NETWORT_UNLOCK_ENUM
ö��˵��  : �������������������ö��

  1.��    ��   : 2016��4��3��
    ��    ��   : d00212987
    �޸�����   : ����������Ŀ����
*****************************************************************************/
enum SC_PERSONALIZATION_NETWORT_UNLOCK_ENUM
{
    SC_PERSONALIZATION_NETWORT_UNLOCK_UNSUPPORT       = 0x00, /* ��֧��������� */
    SC_PERSONALIZATION_NETWORT_UNLOCK_SUPPORT         = 0x01, /* ֧��������� */

   SC_PERSONALIZATION_NETWORT_UNLOCK_BUTT
};
typedef VOS_UINT8 SC_PERSONALIZATION_NETWORT_UNLOCK_ENUM_UINT8;

/*****************************************************************************
ö����    : SC_PERSONALIZATION_INDICATOR_ENUM
ö��˵��  : ָ������������������ģʽ

  1.��    ��   : 2012��4��3��
    ��    ��   : w00184875
    �޸�����   : V7R1C51 ����������Ŀ����
*****************************************************************************/
enum SC_PERSONALIZATION_INDICATOR_ENUM
{
    SC_PERSONALIZATION_INDICATOR_INACTIVE                   = 0x00, /* ȫ���� */
    SC_PERSONALIZATION_INDICATOR_ACTIVE                     = 0x01, /* ȫ�� */
    SC_PERSONALIZATION_INDICATOR_ACTIVE_MODEM0              = 0x02, /* ������ */

    SC_PERSONALIZATION_INDICATOR_BUTT
};
typedef VOS_UINT8 SC_PERSONALIZATION_INDICATOR_ENUM_UINT8;


/*****************************************************************************
ö����    : SC_PERSONALIZATION_STATUS_ENUM
ö��˵��  : ָ���������������͵�״̬

  1.��    ��   : 2012��4��3��
    ��    ��   : w00184875
    �޸�����   : V7R1C51 ����������Ŀ����
*****************************************************************************/
enum SC_PERSONALIZATION_STATUS_ENUM
{
    SC_PERSONALIZATION_STATUS_READY     = 0x00, /* �Ѿ����� */
    SC_PERSONALIZATION_STATUS_PIN       = 0x01, /* δ����״̬������������� */
    SC_PERSONALIZATION_STATUS_PUK       = 0x02, /* Block״̬��������UnBlock�� */

    SC_PERSONALIZATION_STATUS_BUTT
};
typedef VOS_UINT8 SC_PERSONALIZATION_STATUS_ENUM_UINT8;


/*****************************************************************************
ö����    : SC_VERIFY_SIMLOCK_RESULT_ENUM
ö��˵��  : ����У��Ľ��

  1.��    ��   : 2012��4��3��
    ��    ��   : w00184875
    �޸�����   : V7R1C51 ����������Ŀ����
*****************************************************************************/
enum SC_VERIFY_SIMLOCK_RESULT_ENUM
{
    SC_VERIFY_SIMLOCK_RESULT_READY            = 0x00, /* READY: MT is not pending for any simlock */
    SC_VERIFY_SIMLOCK_RESULT_PH_NET_PIN       = 0x01, /* PH-NET PIN: MT is waiting network personalization password to be given */
    SC_VERIFY_SIMLOCK_RESULT_PH_NET_PUK       = 0x02, /* PH-NET PUK: MT is waiting network personalization unblocking password to be given */
    SC_VERIFY_SIMLOCK_RESULT_PH_NETSUB_PIN    = 0x03, /* PH-NETSUB PIN: MT is waiting network subset personalization password to be given */
    SC_VERIFY_SIMLOCK_RESULT_PH_NETSUB_PUK    = 0x04, /* PH-NETSUB PUK: MT is waiting network subset personalization unblocking password to be given */
    SC_VERIFY_SIMLOCK_RESULT_PH_SP_PIN        = 0x05, /* PH-SP PIN: MT is waiting service provider personalization password to be given */
    SC_VERIFY_SIMLOCK_RESULT_PH_SP_PUK        = 0x06, /* PH-SP PUK: MT is waiting service provider personalization unblocking password to be given */
    SC_VERIFY_SIMLOCK_RESULT_PH_CP_PIN        = 0x07, /* PH-CP PIN: MT is waiting corporate personalization password to be given */
    SC_VERIFY_SIMLOCK_RESULT_PH_CP_PUK        = 0x08, /* PH-CP PUK: MT is waiting corporate personalization unblocking password to be given */

    SC_VERIFY_SIMLOCK_RESULT_BUTT
};
typedef VOS_UINT8 SC_VERIFY_SIMLOCK_RESULT_ENUM_UINT8;


/*****************************************************************************
ö����    : SC_PORT_STATUS_ENUM
ö��˵��  : �˿���״̬(HSIC��OM�˿�)

  1.��    ��   : 2012��4��4��
    ��    ��   : w00184875
    �޸�����   : V7R1C51 ����������Ŀ����
*****************************************************************************/
enum SC_PORT_STATUS_ENUM
{
    SC_PORT_STATUS_OFF                  = 0x00, /* �˿ڹر� */
    SC_PORT_STATUS_ON                   = 0x01, /* �˿ڴ� */

    SC_PORT_STATUS_BUTT
};
typedef VOS_UINT32 SC_PORT_STATUS_ENUM_UINT32;

/* Added by L47619 for V9R1 vSIM Project, 2013-8-27, begin */
/*****************************************************************************
ö����    : SC_DH_KEY_TYPE_ENUM
ö��˵��  : DH�㷨ʹ�õ���Կ����

  1.��    ��   : 2013��8��27��
    ��    ��   : L47619
    �޸�����   : V9R1 vSIM��Ŀ�޸�

*****************************************************************************/
enum SC_DH_KEY_TYPE_ENUM
{
    SC_DH_KEY_SERVER_PUBLIC_KEY         = 0x00,             /* ��������Կ */
    SC_DH_KEY_MODEM_PUBLIC_KEY          = 0x01,             /* MODEM�๫Կ */
    SC_DH_KEY_MODEM_PRIVATE_KEY         = 0x02,             /* MODEM��˽Կ */

    SC_DH_KEY_BUTT
};
typedef VOS_UINT32 SC_DH_KEY_TYPE_ENUM_UINT32;
/* Added by L47619 for V9R1 vSIM Project, 2013-8-27, end */


/*****************************************************************************
  4 ȫ�ֱ�������
*****************************************************************************/

/*****************************************************************************
  6 ��Ϣ����
*****************************************************************************/


/*****************************************************************************
  7 STRUCT����
*****************************************************************************/
/*****************************************************************************
�ṹ��    : SC_PH_LOCK_CODE_STRU
�ṹ˵��  : ���������Ŷνṹ

  1.��    ��   : 2012��4��3��
    ��    ��   : w00184875
    �޸�����   : ��ʼ����
*****************************************************************************/
typedef struct
{
   VOS_UINT8                            aucPhLockCodeBegin[SC_MAX_CODE_LEN];
   VOS_UINT8                            aucPhLockCodeEnd[SC_MAX_CODE_LEN];
}SC_PH_LOCK_CODE_STRU;

/*****************************************************************************
 �ṹ��    : SC_SIMLOCK_CARD_FILE_INFO_STRU
 �ṹ˵��  : ��������У������SIM���ļ�����

 �޸���ʷ      :
  1.��    ��   : 2017��03��1��
    ��    ��   : d00212987
    �޸�����   : Dallas C60 �����������ݽṹ��չ��Ŀ����
*****************************************************************************/
typedef struct
{
    USIMM_CARDAPP_STATUS_STRU           stUsimSimInfo;  /* GUL SIM״̬ */
    USIMM_CARDAPP_STATUS_STRU           stCsimUimInfo;  /* CDMA SIM״̬ */
    USIMM_CARDAPP_STATUS_STRU           stIsimInfo;     /* ISIM״̬ */
}SC_SIMLOCK_CARD_FILE_INFO_STRU;

#if (FEATURE_ON == FEATURE_BOSTON_AFTER_FEATURE)
/*****************************************************************************
�ṹ��    : SC_WRITE_SIMLOCK_DATA_STRU
�ṹ˵��  : �ṩ��NAS����AT^SIMLOCKDATAWRITEд��SIMLOCK��Ϣ�����ݽṹ��

  2.��    ��   : 2016��05��07��
    ��    ��   : d00212987
    �޸�����   : ���������㷨������Ŀ�޸�
*****************************************************************************/
typedef struct
{
    VOS_UINT32                                              ulHealdFlag;           /* ��������ͷ��Ϣ��־ Ĭ��ֵ0x5A5AA5A5 */
    VOS_UINT32                                              ulVersionInfo;         /* ���������汾  Ĭ��ֵ��1*/
    VOS_UINT8                                               ucSupportModemNum;     /* ֧��modem���������֧��8��modem */
    VOS_UINT8                                               ucNeedSimlockModemNum; /* ��Ҫ������MODEM����,���ڹ��߻ض�У�� */
    SC_PERSONALIZATION_INDICATOR_ENUM_UINT8                 acIndicator[8];        /* ÿ�������±��Ӧmodem Id,ֵ��ʾ��������״̬��δ����0/����1/����2
                                                                                                ����ucSupportModemNumָʾ֧��3��modem,����modem0����modem1����,modem2����������
                                                                                                acIndicator[8] = {1,0,1,0,0,0,0,0}*/
    VOS_UINT8                                               ucSCDataCfg;           /* ����modemʹ����ͬ�������ݣ�0 / ÿ��modemʹ�õ����������ݣ�1
                                                                                                 ��ͷ��Ϣ��ucSCDataCfg��1�����һЩ������Ӫ�̣�ÿ��modemʹ�õ����������ݣ���
                                                                                                 ���� 3��modem����ÿһ������3�ݣ�modem number��Ӧ�����±� */

    VOS_UINT8                                               ucSupportCategoryNum;  /* ֧�ֶ��ٲ���: 3/4/5/...�� */
    VOS_UINT16                                              ausCategoryDataSize[6];/* ÿ�������±���д��Ӧÿһ������������д�ò��������ݴ�С,��λ�ֽ�
                                                                                                 ����ucSupportCategoryNumָʾ֧��3���������ʾ֧������������������SP,���ÿ���������ݴ�СΪ1k,2k,3k
                                                                                                 �� ausCategoryDataSize[6];  = {1024,2048,3072,0,0,0}
                                                                                                 �������ÿһ�������ݴ�С�������ͬ��modemʹ�ò�ͬ���������ݣ��Ǵ�С�Ǽ���modem �����ݵ��ܺ� */

    SC_PERSONALIZATION_NETWORT_UNLOCK_ENUM_UINT8            enNetworkUnlock;       /* ��֧�� 0/֧��1 �������(�粻֧������������տڲ��ܼӽ�����ֻҪ��һ����֧������ӽ���������ֶ����֧��) */
    VOS_UINT8                                               aucRsv[31];            /* �����ֶ� Ĭ��ֵΪ0*/

}SC_WRITE_SIMLOCK_HEAD_STRU;
#endif

#if (FEATURE_ON == FEATURE_SC_DATA_STRUCT_EXTERN)

/*****************************************************************************
�ṹ��    : SC_PH_LOCK_CP_CODE_STRU
�ṹ˵��  : ���������Ŷνṹ

 �޸���ʷ      :
  1.��    ��   : 2017��03��1��
    ��    ��   : d00212987
    �޸�����   : Dallas C60 �����������ݽṹ��չ��Ŀ����
*****************************************************************************/
typedef struct
{
   VOS_UINT8                            aucPhLockCodeBegin[SC_CP_MAX_CODE_LEN];
   VOS_UINT8                            aucPhLockCodeEnd[SC_CP_MAX_CODE_LEN];
}SC_PH_LOCK_CP_CODE_STRU;

/*****************************************************************************
�ṹ��    : SC_SIMLOCK_CATEGORY_STRU
�ṹ˵��  : �ṩ��NAS��ȡSIMLOCK��Ϣ�Ļ������ݽṹ��
            ��������������Catetory����ӦIndicator����ӦStatus��������������ʣ���������
            �Ŷ������Ŷ������begin/end

 �޸���ʷ      :
  1.��    ��   : 2017��03��1��
    ��    ��   : d00212987
    �޸�����   : Dallas C60 �����������ݽṹ��չ��Ŀ����
*****************************************************************************/
typedef struct
{
    SC_PERSONALIZATION_CATEGORY_ENUM_UINT8                  enCategory          : 3;        /* ����������category���ָʾ 0/1/2/3/4���� */
    SC_PERSONALIZATION_PLATFORM_ENUM_UINT8                  enPlatform          : 1;        /* ������������G:0 /C:1*/
    SC_PERSONALIZATION_NETWORT_UNLOCK_ENUM_UINT8            enNetworkUnlock     : 1;        /* ����ӽ��� ��֧��0/֧��1 */
    SC_PERSONALIZATION_SUPPORT_LIST_ENUM_UINT8              enSupportListType   : 2;        /* ��������������ģʽ ������0/������1 */
    SC_PERSONALIZATION_SUPPORT_CORPORATE_ENUM_UINT8         enSupportCorporate  : 1;        /* ���������Ƿ�֧�������� ��֧��0/֧��1 */

    SC_PERSONALIZATION_INDICATOR_ENUM_UINT8                 enIndicator         : 4;        /* ���������ļ���ָʾ  δ����0/����1/������2 ... */
    VOS_UINT8                                               ucRsv               : 4;

    SC_PERSONALIZATION_STATUS_ENUM_UINT8                    enStatus;                    /* ���������ĵ�ǰ״̬ */
    VOS_UINT8                                               ucMaxUnlockTimes;            /* �������������������� */
    VOS_UINT8                                               ucRemainUnlockTimes;         /* ����������ʣ��������� */
    VOS_UINT8                                               aucReserved[2];              /* �����ֽڣ��������ֽڶ��� */
    VOS_UINT8                                               ucGroupNum;                  /* �Ŷθ�����һ��begin/end��һ���Ŷ� */
    SC_PH_LOCK_CODE_STRU                                    astLockCode[SC_MAX_CODE_NUM];/* ���������ĺŶ�����*/
}SC_SIMLOCK_CATEGORY_STRU;

/*****************************************************************************
�ṹ��    : SC_SIMLOCK_CP_CATEGORY_STRU
�ṹ˵��  : �ṩ��NAS��ȡSIMLOCK��Ϣ�Ļ������ݽṹ��
            ��������������Catetory����ӦIndicator����ӦStatus��������������ʣ���������
            �Ŷ������Ŷ������begin/end

 �޸���ʷ      :
  1.��    ��   : 2017��03��1��
    ��    ��   : d00212987
    �޸�����   : Dallas C60 �����������ݽṹ��չ��Ŀ����
*****************************************************************************/
typedef struct
{
    SC_PERSONALIZATION_CATEGORY_ENUM_UINT8                  enCategory          : 3;        /* ����������category���ָʾ 0/1/2/3/4���� */
    SC_PERSONALIZATION_PLATFORM_ENUM_UINT8                  enPlatform          : 1;        /* ������������G:0 /C:1*/
    SC_PERSONALIZATION_NETWORT_UNLOCK_ENUM_UINT8            enNetworkUnlock     : 1;        /* ����ӽ��� ��֧��0/֧��1 */
    SC_PERSONALIZATION_SUPPORT_LIST_ENUM_UINT8              enSupportListType   : 2;        /* ��������������ģʽ ������0/������1 */
    SC_PERSONALIZATION_SUPPORT_CORPORATE_ENUM_UINT8         enSupportCorporate  : 1;        /* ���������Ƿ�֧�������� ��֧��0/֧��1 */

    SC_PERSONALIZATION_INDICATOR_ENUM_UINT8                 enIndicator         : 4;        /* ���������ļ���ָʾ  δ����0/����1/������2 ... */
    VOS_UINT8                                               ucRsv               : 4;

    SC_PERSONALIZATION_STATUS_ENUM_UINT8                    enStatus;                    /* ���������ĵ�ǰ״̬ */
    VOS_UINT8                                               ucMaxUnlockTimes;            /* �������������������� */
    VOS_UINT8                                               ucRemainUnlockTimes;         /* ����������ʣ��������� */
    VOS_UINT8                                               aucReserved[2];              /* �����ֽڣ��������ֽڶ��� */
    VOS_UINT8                                               ucGroupNum;                  /* �Ŷθ�����һ��begin/end��һ���Ŷ� */
    SC_PH_LOCK_CP_CODE_STRU                                 astLockCode[SC_MAX_CODE_NUM];/* ���������ĺŶ�����*/
}SC_SIMLOCK_CP_CATEGORY_STRU;

/*****************************************************************************
�ṹ��    : SC_WRITE_SIMLOCK_CP_DATA_STRU
�ṹ˵��  : �ṩ��NAS����AT^SIMLOCKDATAWRITEд��SIMLOCK��Ϣ�����ݽṹ��

  1.��    ��   : 2012��4��3��
    ��    ��   : w00184875
    �޸�����   : ��ʼ����

  2.��    ��   : 2016��05��07��
    ��    ��   : d00212987
    �޸�����   : ���������㷨������Ŀ�޸�
*****************************************************************************/
typedef struct
{
    SC_PERSONALIZATION_CATEGORY_ENUM_UINT8                  enCategory          : 3;        /* ����������category���ָʾ 0/1/2/3/4���� */
    SC_PERSONALIZATION_PLATFORM_ENUM_UINT8                  enPlatform          : 1;        /* ������������G:0 /C:1*/
    SC_PERSONALIZATION_NETWORT_UNLOCK_ENUM_UINT8            enNetworkUnlock     : 1;        /* ����ӽ��� ��֧��0/֧��1 */
    SC_PERSONALIZATION_SUPPORT_LIST_ENUM_UINT8              enSupportListType   : 2;        /* ��������������ģʽ ������0/������1 */
    SC_PERSONALIZATION_SUPPORT_CORPORATE_ENUM_UINT8         enSupportCorporate  : 1;        /* ���������Ƿ�֧�������� ��֧��0/֧��1 */

    SC_PERSONALIZATION_INDICATOR_ENUM_UINT8                 enIndicator         : 4;        /* ���������ļ���ָʾ  δ����0/����1/������2 ... */
    VOS_UINT8                                               ucRsv               : 4;

    VOS_UINT8                                               ucMaxUnlockTimes;            /* �������������������� */
    VOS_UINT8                                               ucGroupNum;                  /* �Ŷθ�����һ��begin/end��һ���Ŷ� */
    SC_PH_LOCK_CP_CODE_STRU                                 astLockCode[SC_MAX_CODE_NUM];/* ���������ĺŶ�����*/
    /* astLockCodeժҪ���ģ����ɹ��̣�aucSimlockRsaData����astLockCode�Ⱦ���SHA256�㷨����ժҪ��
       Ȼ��ʹ��USB dog�е�˽Կ���м��ܵ�У�����ݡ� ��simlock code�Ϸ��Լ���ʱ����ʹ��AK-File��
       �Ĺ�Կ��aucSimlockRsaData���н��ܣ�Ȼ����astLockCodeʹ��SHA256���ɵ�ժҪ���бȽϡ�*/
    VOS_UINT8                                               aucSimlockRsaData[SC_RSA_ENCRYPT_LEN];
    /* �����Ľ������룬32λpbkdf2���ܺ������ */
    VOS_UINT8                                               aucScLockPin[SC_CRYPTO_PWD_LEN];
    /* �����Ľ������룬32λpbkdf2���ܺ������ */
    VOS_UINT8                                               aucScLockPuk[SC_CRYPTO_PWD_LEN];
    /* ��Ȩ��Կ��ժҪ��HMAC�㷨(��ԿΪSSK)�������ɵ�ժҪ */
    VOS_UINT8                                               aucSignature[SC_SIGNATURE_LEN];
}SC_WRITE_SIMLOCK_CP_DATA_STRU;

/*****************************************************************************
�ṹ��    : SC_WRITE_SIMLOCK_DATA_STRU
�ṹ˵��  : �ṩ��NAS����AT^SIMLOCKDATAWRITEд��SIMLOCK��Ϣ�����ݽṹ��

  1.��    ��   : 2012��4��3��
    ��    ��   : w00184875
    �޸�����   : ��ʼ����

  2.��    ��   : 2016��05��07��
    ��    ��   : d00212987
    �޸�����   : ���������㷨������Ŀ�޸�
*****************************************************************************/
typedef struct
{
    SC_PERSONALIZATION_CATEGORY_ENUM_UINT8                  enCategory          : 3;        /* ����������category���ָʾ 0/1/2/3/4���� */
    SC_PERSONALIZATION_PLATFORM_ENUM_UINT8                  enPlatform          : 1;        /* ������������G:0 /C:1*/
    SC_PERSONALIZATION_NETWORT_UNLOCK_ENUM_UINT8            enNetworkUnlock     : 1;        /* ����ӽ��� ��֧��0/֧��1 */
    SC_PERSONALIZATION_SUPPORT_LIST_ENUM_UINT8              enSupportListType   : 2;        /* ��������������ģʽ ������0/������1 */
    SC_PERSONALIZATION_SUPPORT_CORPORATE_ENUM_UINT8         enSupportCorporate  : 1;        /* ���������Ƿ�֧�������� ��֧��0/֧��1 */

    SC_PERSONALIZATION_INDICATOR_ENUM_UINT8                 enIndicator         : 4;        /* ���������ļ���ָʾ  δ����0/����1/������2 ... */
    VOS_UINT8                                               ucRsv               : 4;

    VOS_UINT8                                               ucMaxUnlockTimes;            /* �������������������� */
    VOS_UINT8                                               ucGroupNum;                  /* �Ŷθ�����һ��begin/end��һ���Ŷ� */
    SC_PH_LOCK_CODE_STRU                                    astLockCode[SC_MAX_CODE_NUM];/* ���������ĺŶ�����*/
    /* astLockCodeժҪ���ģ����ɹ��̣�aucSimlockRsaData����astLockCode�Ⱦ���SHA256�㷨����ժҪ��
       Ȼ��ʹ��USB dog�е�˽Կ���м��ܵ�У�����ݡ� ��simlock code�Ϸ��Լ���ʱ����ʹ��AK-File��
       �Ĺ�Կ��aucSimlockRsaData���н��ܣ�Ȼ����astLockCodeʹ��SHA256���ɵ�ժҪ���бȽϡ�*/
    VOS_UINT8                                               aucSimlockRsaData[SC_RSA_ENCRYPT_LEN];
#if (FEATURE_ON == FEATURE_SC_SEC_UPDATE)
    /* �����Ľ������룬32λpbkdf2���ܺ������ */
    VOS_UINT8                                               aucScLockPin[SC_CRYPTO_PWD_LEN];
    /* �����Ľ������룬32λpbkdf2���ܺ������ */
    VOS_UINT8                                               aucScLockPuk[SC_CRYPTO_PWD_LEN];
    /* ��Ȩ��Կ��ժҪ��HMAC�㷨(��ԿΪSSK)�������ɵ�ժҪ */
    VOS_UINT8                                               aucSignature[SC_SIGNATURE_LEN];

#else
    /* �����Ľ������룬��16λ��PIN��ʹ��USB dog�е�˽Կ���м��ܵ����� */
    VOS_UINT8                                               aucScLockPin[SC_RSA_ENCRYPT_LEN];
    /* ������UnBlock���룬��16λ��PUK��ʹ��USB dog�е�˽Կ���м��ܵ����� */
    VOS_UINT8                                               aucScLockPuk[SC_RSA_ENCRYPT_LEN];
#endif
}SC_WRITE_SIMLOCK_DATA_STRU;
#else
/*****************************************************************************
�ṹ��    : SC_SIMLOCK_CATEGORY_STRU
�ṹ˵��  : �ṩ��NAS��ȡSIMLOCK��Ϣ�Ļ������ݽṹ��
            ��������������Catetory����ӦIndicator����ӦStatus��������������ʣ���������
            �Ŷ������Ŷ������begin/end

  1.��    ��   : 2012��4��3��
    ��    ��   : w00184875
    �޸�����   : ��ʼ����
*****************************************************************************/
typedef struct
{
    SC_PERSONALIZATION_CATEGORY_ENUM_UINT8                  enCategory;                  /* ����������category��� */
    SC_PERSONALIZATION_INDICATOR_ENUM_UINT8                 enIndicator;                 /* ���������ļ���ָʾ */
    SC_PERSONALIZATION_STATUS_ENUM_UINT8                    enStatus;                    /* ���������ĵ�ǰ״̬ */
    VOS_UINT8                                               ucMaxUnlockTimes;            /* �������������������� */
    VOS_UINT8                                               ucRemainUnlockTimes;         /* ����������ʣ��������� */
    VOS_UINT8                                               aucReserved[2];              /* �����ֽڣ��������ֽڶ��� */
    VOS_UINT8                                               ucGroupNum;                  /* �Ŷθ�����һ��begin/end��һ���Ŷ� */
    SC_PH_LOCK_CODE_STRU                                    astLockCode[SC_MAX_CODE_NUM];/* ���������ĺŶ�����*/
}SC_SIMLOCK_CATEGORY_STRU;

/*****************************************************************************
�ṹ��    : SC_WRITE_SIMLOCK_DATA_STRU
�ṹ˵��  : �ṩ��NAS����AT^SIMLOCKDATAWRITEд��SIMLOCK��Ϣ�����ݽṹ��

  1.��    ��   : 2012��4��3��
    ��    ��   : w00184875
    �޸�����   : ��ʼ����

  2.��    ��   : 2016��05��07��
    ��    ��   : d00212987
    �޸�����   : ���������㷨������Ŀ�޸�
*****************************************************************************/
typedef struct
{
    SC_PERSONALIZATION_CATEGORY_ENUM_UINT8                  enCategory;                  /* ����������category��� */
    SC_PERSONALIZATION_INDICATOR_ENUM_UINT8                 enIndicator;                 /* ���������ļ���ָʾ */
    VOS_UINT8                                               ucMaxUnlockTimes;            /* �������������������� */
    VOS_UINT8                                               ucGroupNum;                  /* �Ŷθ�����һ��begin/end��һ���Ŷ� */
    SC_PH_LOCK_CODE_STRU                                    astLockCode[SC_MAX_CODE_NUM];/* ���������ĺŶ�����*/
    /* astLockCodeժҪ���ģ����ɹ��̣�aucSimlockRsaData����astLockCode�Ⱦ���SHA256�㷨����ժҪ��
       Ȼ��ʹ��USB dog�е�˽Կ���м��ܵ�У�����ݡ� ��simlock code�Ϸ��Լ���ʱ����ʹ��AK-File��
       �Ĺ�Կ��aucSimlockRsaData���н��ܣ�Ȼ����astLockCodeʹ��SHA256���ɵ�ժҪ���бȽϡ�*/
    VOS_UINT8                                               aucSimlockRsaData[SC_RSA_ENCRYPT_LEN];
#if (FEATURE_ON == FEATURE_SC_SEC_UPDATE)
    /* �����Ľ������룬32λpbkdf2���ܺ������ */
    VOS_UINT8                                               aucScLockPin[SC_CRYPTO_PWD_LEN];
    /* �����Ľ������룬32λpbkdf2���ܺ������ */
    VOS_UINT8                                               aucScLockPuk[SC_CRYPTO_PWD_LEN];
    /* ��Ȩ��Կ��ժҪ��HMAC�㷨(��ԿΪSSK)�������ɵ�ժҪ */
    VOS_UINT8                                               aucSignature[SC_SIGNATURE_LEN];

#else
    /* �����Ľ������룬��16λ��PIN��ʹ��USB dog�е�˽Կ���м��ܵ����� */
    VOS_UINT8                                               aucScLockPin[SC_RSA_ENCRYPT_LEN];
    /* ������UnBlock���룬��16λ��PUK��ʹ��USB dog�е�˽Կ���м��ܵ����� */
    VOS_UINT8                                               aucScLockPuk[SC_RSA_ENCRYPT_LEN];
#endif
}SC_WRITE_SIMLOCK_DATA_STRU;

#endif

/*****************************************************************************
�ṹ��    : SC_SET_FAC_AUTH_PUB_KEY_STRU
�ṹ˵��  : �ṩ��NAS����AT^FACAUTHPUBKEYд���Ȩ��Կ�����ݽṹ

  1.��    ��   : 2012��4��3��
    ��    ��   : w00184875
    �޸�����   : ��ʼ����

  2.��    ��   : 2016��05��07��
    ��    ��   : d00212987
    �޸�����   : ���������㷨������Ŀ�޸�
*****************************************************************************/
typedef struct
{
    VOS_UINT8       aucAuthPubKey[SC_AUTH_PUB_KEY_TOTAL_LEN];   /* ��Ȩ��Կ:����2����Կ������ */
    VOS_UINT8       aucSignature[SC_SIGNATURE_LEN];       /* ��Ȩ��Կ��ժҪ��AES-ECB�㷨(��ԿΪSSK)�������ɵ�ժҪǩ�����°汾��hmac���� */
}SC_SET_FAC_AUTH_PUB_KEY_STRU;


/*****************************************************************************
�ṹ��    : SC_IDENTIFY_START_RESPONSE_STRU
�ṹ˵��  : �ṩ��NAS����AT^IDENTIFYSTART���ڻ�ȡ<identify_start_response>���������ݽṹ

  1.��    ��   : 2012��4��3��
    ��    ��   : w00184875
    �޸�����   : ��ʼ����
*****************************************************************************/
typedef struct
{
    /* SC��ȡ����������ù�Կ����RSA���ܺ������ */
    VOS_UINT8       aucIdentifyStartRsp[SC_RSA_ENCRYPT_LEN];
}SC_IDENTIFY_START_RESPONSE_STRU;


/*****************************************************************************
�ṹ��    : SC_IDENTIFY_END_REQUEST_STRU
�ṹ˵��  : NAS������AT^IDENTIFYEND�е�<identify_end_request>�����ύ��SCʱʹ�õ����ݽṹ

  1.��    ��   : 2012��4��3��
    ��    ��   : w00184875
    �޸�����   : ��ʼ����
*****************************************************************************/
typedef struct
{
    /* ��̨ͨ��˽Կ��<identify_start_response>�������������������˽Կ���������������<identify_end_request>��
       ͨ������^IDENTIFYEND����<identify_end_request>���͸�Э��ջ��Э��ջʹ�ø����ݺͲ��߼�Ȩ��Կ��ԭ�������
       ����ԭ�������ԭ�����һ�����Ȩͨ�������򣬼�Ȩʧ�� */
    VOS_UINT8       aucIdentifyEndReq[SC_RSA_ENCRYPT_LEN];
}SC_IDENTIFY_END_REQUEST_STRU;


/*****************************************************************************
�ṹ��    : SC_SET_PORT_ATTRIBUTE_STRU
�ṹ˵��  : NAS������AT^PORTATTRSET�е�<onoff>��<port_passwd>�ύ��SCʱʹ�õ����ݽṹ

  1.��    ��   : 2012��4��3��
    ��    ��   : w00184875
    �޸�����   : ��ʼ����
*****************************************************************************/
typedef struct
{
    /* AT����^IDENTIFYEND�еĲ���<onoff>��ֵ */
    SC_PORT_STATUS_ENUM_UINT32          enStatus;

    /* AT����^IDENTIFYEND�еĲ���<port_passwd>��ֵ��<port_passwd>Ϊ16λ���루���볤��
       Ϊ�̶���16����0��-��9���ַ�������RSA�������ɵ�128�ֽ����� */
    VOS_UINT8                           aucRsaPwd[SC_RSA_ENCRYPT_LEN];
}SC_SET_PORT_ATTRIBUTE_STRU;

/*****************************************************************************
 �ṹ��    : SC_CK_CATEGORY_STRU
 �ṹ˵��  : ÿһ������CK/UK���뱣�淽ʽ

  1.��    ��   : 2012��4��7��
    ��    ��   : w00184875
    �޸�����   : AP-Modem����������Ŀ�����ṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           aucCKCryptoPwd[SC_CRYPTO_PWD_LEN]; /* CK���� */
    VOS_UINT8                           aucUKCryptoPwd[SC_CRYPTO_PWD_LEN]; /* UK���� */
}SC_CK_CATEGORY_STRU;


/*****************************************************************************
 �ṹ��    : SC_PI_FILE_STRU
 �ṹ˵��  : PI�ļ������ݽṹ

  1.��    ��   : 2012��04��07��
    ��    ��   : w00184875
    �޸�����   : AP-Modem����������Ŀ�����ṹ
*****************************************************************************/

typedef struct
{
    /* Ŀǰ֧��3��category���ṹ�����鰴��network->network subset->SP��˳������ */
    SC_SIMLOCK_CATEGORY_STRU            astSimlockCategory[SC_MAX_SUPPORT_CATEGORY];
}SC_PI_FILE_STRU;

/*****************************************************************************
 �ṹ��    : SC_CK_FILE_STRU
 �ṹ˵��  : CK-FILE�Ĵ洢�ṹ
             ����3��Category����Ӧ��CK/UK���룬���Ĵ洢

  1.��    ��   : 2012��04��07��
    ��    ��   : w00184875
    �޸�����   : AP-Modem����������Ŀ�����ṹ
*****************************************************************************/
typedef struct
{
    /* Ŀǰ֧��3��category���ṹ�����鰴��network->network subset->SP��˳������ */
    SC_CK_CATEGORY_STRU                 astCKCategory[SC_MAX_SUPPORT_CATEGORY];
}SC_CK_FILE_STRU;

/*****************************************************************************
 �ṹ��    : SC_DK_FILE_STRU
 �ṹ˵��  : DK�ļ������ݽṹ

  1.��    ��   : 2012��04��07��
    ��    ��   : w00184875
    �޸�����   : AP-Modem����������Ŀ�����ṹ
*****************************************************************************/
typedef struct
{
    SC_PORT_STATUS_ENUM_UINT32          enPortStatus;       /* �˿���״̬������ */
    VOS_UINT8                           aucDKCryptoPwd[SC_CRYPTO_PWD_LEN]; /* DK���� */
}SC_DK_FILE_STRU;

/*****************************************************************************
 �ṹ��    : SC_AK_FILE_STRU
 �ṹ˵��  : AK�ļ������ݽṹ

  1.��    ��   : 2012��04��07��
    ��    ��   : w00184875
    �޸�����   : AP-Modem����������Ŀ�����ṹ

  2.��    ��   : 2016��05��07��
    ��    ��   : d00212987
    �޸�����   : ���������㷨������Ŀ�޸�
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           aucAuthPubKey_A[SC_AUTH_PUB_KEY_LEN];    /* AK1��Կ����Կ���� */
    VOS_UINT8                           aucAuthPubKey_B[SC_AUTH_PUB_KEY_LEN];    /* AK2��Կ����Կ���� */
}SC_AK_FILE_STRU;

/*****************************************************************************
 �ṹ��    : SC_SIGN_FILE_STRU
 �ṹ˵��  : ǩ���ļ������ݽṹ

  1.��    ��   : 2012��04��09��
    ��    ��   : w00184875
    �޸�����   : AP-Modem����������Ŀ�����ṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           aucSignature[SC_SIGNATURE_LEN];    /* ǩ���ļ����� */
}SC_SIGN_FILE_STRU;

/*****************************************************************************
�ṹ��    : SC_SIMLOCK_INFO_STRU
�ṹ˵��  : �ṩ��NAS��ȡSIMLOCK��Ϣ�����ݽṹ��
            ����3��Category����Ӧ����������Ϣ

  1.��    ��   : 2012��4��3��
    ��    ��   : w00184875
    �޸�����   : AP-Modem����������Ŀ�����ṹ
*****************************************************************************/
typedef SC_PI_FILE_STRU SC_SIMLOCK_INFO_STRU;

/*****************************************************************************
 �ṹ��    : SC_IMEI_SEC_STRU
 �ṹ˵��  : �����·�����IMEI

  1.��    ��   : 2017��07��07��
    ��    ��   : d00212987
    �޸�����   : �����ṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           *pucRsaIMEI;                    /* Rsa���ܺ������ */
    VOS_UINT32                           ulRsaIMEILen;                  /* Rsa���ܺ�����ĳ��� */
    VOS_UINT8                           *pucHmac;                       /* hmacǩ�� */
    VOS_UINT32                           ulHmacLen;                     /* hmacǩ������ */
}SC_IMEI_SEC_STRU;

/*****************************************************************************
 �ṹ��    : SC_CRYPTO_PIN_STRU
 �ṹ˵��  :

  1.��    ��   : 2017��07��07��
    ��    ��   : d00212987
    �޸�����   : �����ṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT8                            aucCryptoPin[SC_CRYPTO_CBC_PIN_LEN];   /* AES���ܺ������ */
    VOS_UINT32                           aulPinIv[SC_IV_LEN];                   /* IVֵ */
    VOS_UINT8                            aucHmacValue[SC_SIGNATURE_LEN];        /* hmacǩ�� */
}SC_CRYPTO_PIN_STRU;

/*****************************************************************************
  8 UNION����
*****************************************************************************/

/*****************************************************************************
  9 OTHERS����
*****************************************************************************/


/*****************************************************************************
  10 ��������
*****************************************************************************/
/*****************************************************************************
 �� �� ��  : SC_PERS_GetSimlockInfo
 ��������  : NASͨ���ýӿڻ�ȡSIMLOCK��Ϣ
 �������  : pstSimlockInfo:��ȡSIMLOCK��Ϣ�����ݽṹ���ɵ����������ڴ�
 �������  : NA
 �� �� ֵ  : SC_ERROR_CODE_ENUM_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��4��3��
    ��    ��   : w00184875
    �޸�����   : ��ʼ����

*****************************************************************************/
extern SC_ERROR_CODE_ENUM_UINT32 SC_PERS_GetSimlockInfo(SC_SIMLOCK_INFO_STRU *pstSimlockInfo);


#if (FEATURE_ON == FEATURE_SC_NETWORK_UPDATE)
/*****************************************************************************
 �� �� ��  : SC_PERS_WriteNWSimLockData
 ��������  : NAS�յ�AT^SIMLOCKNWUPDATE���ͨ���ýӿ�д��SIMLOCK��Ϣ
 �������  : ulLayer ����д��һ������
             pucSimlockData:   ������������
             ulSimlockDataLen: �����������ݳ���
             puchmac:          ������������hmac������У������
             ulhmacLen:        ������������hmac������У����������
 �������  : NA
 �� �� ֵ  : SC_ERROR_CODE_ENUM_UINT32���͵�SC������

  1.��    ��   : 2017��03��6��
    ��    ��   : l00383907
    �޸�����   : Dallas C60 �����������ݽṹ��չ��Ŀ����
*****************************************************************************/
extern SC_ERROR_CODE_ENUM_UINT32 SC_PERS_WriteNWSimLockData(
    VOS_UINT32                           ulLayer,
    VOS_UINT8                           *pucSimlockData,
    VOS_UINT32                           ulSimlockDataLen,
    VOS_UINT8                           *pucHmac,
    VOS_UINT32                           ulHmacLen
);
#endif

#if ((FEATURE_ON == FEATURE_SC_DATA_STRUCT_EXTERN) || (FEATURE_ON == FEATURE_BOSTON_AFTER_FEATURE))
/*****************************************************************************
 �� �� ��  : SC_PERS_WriteSimLockDataEx
 ��������  : NAS�յ�AT^SIMLOCKDATAWRITEEX���ͨ���ýӿ�д��SIMLOCK��Ϣ
 �������  : ulLayer:          ����д��һ������
             pucSimlockData:   �����������ݳ���
             ulSimlockDataLen: ������������
             puchmac:          ������������hmac������У������
             ulhmacLen:        ������������hmac������У����������

 �������  : NA
 �� �� ֵ  : SC_ERROR_CODE_ENUM_UINT32���͵�SC������

  1.��    ��   : 2017��03��1��
    ��    ��   : d00212987
    �޸�����   : Dallas C60 �����������ݽṹ��չ��Ŀ����
*****************************************************************************/
extern SC_ERROR_CODE_ENUM_UINT32 SC_PERS_WriteSimLockDataEx(
    VOS_UINT32                          ulLayer,
    VOS_UINT8                          *pucSimlockData,
    VOS_UINT32                          ulSimlockDataLen,
    VOS_UINT8                          *pucHmac,
    VOS_UINT32                          ulHmacLen
);

/*****************************************************************************
 �� �� ��  : SC_PERS_ReadSimLockDataEx
 ��������  : NASͨ���ýӿڻ�ȡ�������ݽṹ��չ���ĳһ������������Ϣ
 �������  : ulLayer            : ָʾ��ȡ��һ����������
             pucSimlockDatabuf  : ��ȡSIMLOCK��Ϣ�ռ䣬�ɵ����������ڴ�
             ulSimlockDatabufLen: �ռ䳤��

 �������  : pulSimlockDataLen   : ��ʵ�������ݳ���

 �� �� ֵ  : SC_ERROR_CODE_ENUM_UINT32

 �޸���ʷ      :
  1.��    ��   : 2017��03��1��
    ��    ��   : d00212987
    �޸�����   : Dallas C60 �����������ݽṹ��չ��Ŀ����
*****************************************************************************/
extern SC_ERROR_CODE_ENUM_UINT32 SC_PERS_ReadSimLockDataEx(
    VOS_UINT32                           ulLayer,
    VOS_UINT8                           *pucSimlockDatabuf,
    VOS_UINT32                           ulSimlockDatabufLen,
    VOS_UINT32                          *pulSimlockDataLen
);
#else

/*****************************************************************************
 �� �� ��  : SC_PERS_WriteSimLockData
 ��������  : NAS�յ�AT^SIMLOCKDATAWRITE���ͨ���ýӿ�д��SIMLOCK��Ϣ
 �������  : pstWriteSimLockData: ��д��PI-FILE��CK-File��SIMLOCK��Ϣ

 �������  : NA
 �� �� ֵ  : SC_ERROR_CODE_ENUM_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��4��3��
    ��    ��   : w00184875
    �޸�����   : ��ʼ����

*****************************************************************************/
extern SC_ERROR_CODE_ENUM_UINT32 SC_PERS_WriteSimLockData(SC_WRITE_SIMLOCK_DATA_STRU *pstWriteSimLockData);
#endif

#if (FEATURE_ON == FEATURE_SC_DATA_STRUCT_EXTERN)

/*****************************************************************************
 �� �� ��  : SC_PERS_GetSimLockDataLayerLen
 ��������  : NASͨ���ýӿڻ�ȡ�������ݽṹ��չ���ĳһ������������Ϣ��С
 �������  : ulLayer            : ָʾ��ȡ��һ���������ݴ�С

 �������  : pulSimlockDataLen �����������ݳ���

 �� �� ֵ  : SC_ERROR_CODE_ENUM_UINT32

 �޸���ʷ      :
  1.��    ��   : 2017��03��1��
    ��    ��   : d00212987
    �޸�����   : Dallas C60 �����������ݽṹ��չ��Ŀ����
*****************************************************************************/
extern SC_ERROR_CODE_ENUM_UINT32 SC_PERS_GetSimLockDataLayerLen(
    VOS_UINT32                           ulLayer,
    VOS_UINT32                          *pulSimlockDataLen
);

/*****************************************************************************
 �� �� ��  : SC_PERS_GetSimlockCPInfo
 ��������  : NASͨ���ýӿڻ�ȡ���Ĳ� SIMLOCK��Ϣ
 �������  : pstSimlockInfo:��ȡSIMLOCK��Ϣ�����ݽṹ���ɵ����������ڴ�
 �������  : NA
 �� �� ֵ  : SC_ERROR_CODE_ENUM_UINT32

 �޸���ʷ      :
  1.��    ��   : 2017��03��1��
    ��    ��   : d00212987
    �޸�����   : Dallas C60 �����������ݽṹ��չ��Ŀ����
*****************************************************************************/
extern SC_ERROR_CODE_ENUM_UINT32 SC_PERS_GetSimlockCPInfo(SC_SIMLOCK_CP_CATEGORY_STRU *pstSimlockCpInfo);
#endif

/*****************************************************************************
 �� �� ��  : SC_PERS_VerifySimLock
 ��������  : ������������У��
 �������  : enModemID:Modem ID

 �������  : pucSimLockResult:��������״̬
 �� �� ֵ  : SC_ERROR_CODE_ENUM_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��04��07��
    ��    ��   : w00184875
    �޸�����   : AP-Modem����������Ŀ��������

*****************************************************************************/
extern SC_ERROR_CODE_ENUM_UINT32 SC_PERS_VerifySimLock(
    SC_VERIFY_SIMLOCK_RESULT_ENUM_UINT8 *penVerifySimlockRslt,
    MODEM_ID_ENUM_UINT16                 enModemID
);

/*****************************************************************************
 �� �� ��  : SC_PERS_NoVerifyNvReadImei
 ��������  : ��ȡ����NV���IMEI
             ˵��:��ȥУ�飬ֱ��ȥ��NV,������NV_Read�ӿڣ�SC_PERS_NoVerifyNvReadImei�ӿ���modem2 IMEIûд������£���ȡmodem0
 �������  : enModemID : Modem ID
             usID      : Nv id
             ulLength  : Nv ����

 �������  : *pItem    : ��ȡNV ����
 �� �� ֵ  : SC_ERROR_CODE_ENUM_UINT32

 �޸���ʷ      :
  1.��    ��   : 2015��11��30��
    ��    ��   : d00212987
    �޸�����   : IMEI��֤
*****************************************************************************/
SC_ERROR_CODE_ENUM_UINT32 SC_PERS_NoVerifyNvReadImei(
    MODEM_ID_ENUM_UINT16                enModemID,
    VOS_UINT16                          usID,
    VOS_VOID                           *pItem,
    VOS_UINT32                          ulLength
);

/*****************************************************************************
 �� �� ��  : SC_PERS_VerifyNvReadImei
 ��������  : ��ȡ����NV���IMEI,����IMEI��֤(����ֵΪ:SC_ERROR_CODE_NO_ERROR,��ȡ��NV���ݿ��ã����򲻿���)
             ˵��:��У��IMEI�ŵĺϷ��ԣ�Ȼ���ٶ�ȡNV�����IMEI�ŷǷ�����ȫ0 IMEI,������modem2 imei ûд������£���ȡmodem0
 �������  : enModemID : Modem ID
             usID      : Nv id
             ulLength  : Nv ����

 �������  : *pItem    : ��ȡNV ����
 �� �� ֵ  : SC_ERROR_CODE_ENUM_UINT32

 �޸���ʷ      :
  1.��    ��   : 2013��5��25��
    ��    ��   : d00212987
    �޸�����   : IMEI��֤
*****************************************************************************/
SC_ERROR_CODE_ENUM_UINT32 SC_PERS_VerifyNvReadImei(
    MODEM_ID_ENUM_UINT16                enModemID,
    VOS_UINT16                          usID,
    VOS_VOID                           *pItem,
    VOS_UINT32                          ulLength
);

/*****************************************************************************
 �� �� ��  : SC_PERS_UnLock
 ��������  : ������UNBLOC����
 �������  : pcPwd: ��������
             ucLen: ���볤��
             enModemID:Modem ID
 �������  : pucSimLockResult:�������������������״̬
 �� �� ֵ  : SC_ERROR_CODE_ENUM_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��04��07��
    ��    ��   : w00184875
    �޸�����   : AP-Modem����������Ŀ��������

*****************************************************************************/
extern SC_ERROR_CODE_ENUM_UINT32 SC_PERS_UnLock(
    VOS_UINT8                           *pucPwd,
    VOS_UINT8                            ucLen,
    SC_VERIFY_SIMLOCK_RESULT_ENUM_UINT8 *penVerifySimlockRslt,
    MODEM_ID_ENUM_UINT16                 enModemID
);

/*****************************************************************************
 �� �� ��  : SC_FAC_SetFacAuthPubKey
 ��������  : NAS�յ�AT^FACAUTHPUBKEY��ͨ���ýӿ�д���Ȩ��Կ
 �������  : pstSetFacAuthPubKey: ��Ȩ��Կ���ݽṹ

 �������  : NA
 �� �� ֵ  : SC_ERROR_CODE_ENUM_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��4��3��
    ��    ��   : w00184875
    �޸�����   : ��ʼ����

*****************************************************************************/
extern SC_ERROR_CODE_ENUM_UINT32 SC_FAC_SetFacAuthPubKey(SC_SET_FAC_AUTH_PUB_KEY_STRU *pstSetFacAuthPubKey);


/*****************************************************************************
 �� �� ��  : SC_FAC_StartIdentify
 ��������  : NAS�յ�AT^IDENTIFYSTART��ͨ���ýӿڻ�ȡ<identify_start_response>����
 �������  : NA

 �������  : pstIdentifyStartRsp: ���ڻ�ȡ<identify_start_response>���������ݽṹ��
             �ɵ����������ڴ�
 �� �� ֵ  : SC_ERROR_CODE_ENUM_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��4��3��
    ��    ��   : w00184875
    �޸�����   : ��ʼ����

*****************************************************************************/
extern SC_ERROR_CODE_ENUM_UINT32 SC_FAC_StartIdentify(SC_IDENTIFY_START_RESPONSE_STRU *pstIdentifyStartRsp);


/*****************************************************************************
 �� �� ��  : SC_FAC_EndIdentify
 ��������  : NAS�յ�AT^IDENTIFYEND�����ͨ���ýӿڽ�<identify_end_request>�����ύ��SC
 �������  : pstIdentifyEndReq: ���ڴ洢<identify_end_request>���������ݽṹ

 �������  : NA
 �� �� ֵ  : SC_ERROR_CODE_ENUM_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��4��3��
    ��    ��   : w00184875
    �޸�����   : ��ʼ����

*****************************************************************************/
extern SC_ERROR_CODE_ENUM_UINT32 SC_FAC_EndIdentify(SC_IDENTIFY_END_REQUEST_STRU *pstIdentifyEndReq);


/*****************************************************************************
 �� �� ��  : SC_FAC_RsaEncrypt
 ��������  : NAS�յ�AT^PHONEPHYNUM?��ѯ���ͨ���ýӿڶ�����Ž���RSA����
 �������  : pcRawData: ����ţ����Ĵ洢
             ulLen: ����ų���
             pcCipherData: RSA���ܺ������
             pulCipherLen: RSA���ܺ�����ĳ���

 �������  : NA
 �� �� ֵ  : SC_ERROR_CODE_ENUM_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��4��3��
    ��    ��   : w00184875
    �޸�����   : ��ʼ����

*****************************************************************************/
extern SC_ERROR_CODE_ENUM_UINT32 SC_FAC_RsaEncrypt(
    VOS_UINT8   *pucRawData,
    VOS_UINT32   ulLen,
    VOS_UINT8   *pucCipherData,
    VOS_UINT32  *pulCipherLen
);


/*****************************************************************************
 �� �� ��  : SC_FAC_RsaDecrypt
 ��������  : NAS�յ�AT^PHONEPHYNUM�������ͨ���ýӿڶ�����Ž���RSA����
 �������  : pcCipherData: ����ţ����Ĵ洢
             ucCipherLen: ��������ĳ���
             pcRawData: RSA���ܺ�����������
             pucLen: RSA���ܺ����������ĳ���

 �������  : NA
 �� �� ֵ  : SC_ERROR_CODE_ENUM_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��4��3��
    ��    ��   : w00184875
    �޸�����   : ��ʼ����

*****************************************************************************/
extern SC_ERROR_CODE_ENUM_UINT32 SC_FAC_RsaDecrypt(
    VOS_UINT8  *pucCipherData,
    VOS_UINT32  ulCipherLen,
    VOS_UINT8  *pucRawData,
    VOS_UINT32 *pulLen
);

/*****************************************************************************
 �� �� ��  : SC_FAC_WriteHUK
 ��������  : NAS�յ�AT^HUK���ͨ����SC��װ�Ľӿ�д��HUK
 �������  : pcHuk: HUK������128bit
             ucLen: HUK��������

 �������  : NA
 �� �� ֵ  : SC_ERROR_CODE_ENUM_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��4��3��
    ��    ��   : w00184875
    �޸�����   : ��ʼ����

*****************************************************************************/
extern SC_ERROR_CODE_ENUM_UINT32 SC_FAC_WriteHUK(VOS_UINT8 *pucHuk, VOS_UINT32 ulLen);

/*****************************************************************************
 �� �� ��  : SC_FAC_WriteIMEI
 ��������  : NAS�յ�AT^PHONEPHYNUM�ͨ����SC��װ�Ľӿڰ�IMEI����д��IMEIFile.bin������ǩ��
 �������  : enModemID    : ��0 ���߿�1
             pucCipherData: IMEI��������
             ulCipherLen  : IMEI������������

 �������  : NA
 �� �� ֵ  : SC_ERROR_CODE_ENUM_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��5��9��
    ��    ��   : d00212987
    �޸�����   : IMEI��֤
*****************************************************************************/
extern SC_ERROR_CODE_ENUM_UINT32 SC_FAC_WriteIMEI(MODEM_ID_ENUM_UINT16    enModemID,
                                                  VOS_UINT8              *pucCipherData,
                                                  VOS_UINT32              ulCipherLen);

/*****************************************************************************
 �� �� ��  : SC_FAC_SetPortAttrib
 ��������  : NAS�յ�AT^PORTATTRIBSET���������ͨ���ýӿڽ��˿���������Ϣ�ύ��SC
 �������  : pstSetPortAttrib: �˿������������Ϣ

 �������  : NA
 �� �� ֵ  : SC_ERROR_CODE_ENUM_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��4��3��
    ��    ��   : w00184875
    �޸�����   : ��ʼ����

*****************************************************************************/
extern SC_ERROR_CODE_ENUM_UINT32 SC_FAC_SetPortAttrib(SC_SET_PORT_ATTRIBUTE_STRU *pstSetPortAttrib);


/*****************************************************************************
 �� �� ��  : SC_FAC_GetPortAttrib
 ��������  : �ú�������������������:
             1.NAS�յ�AT^PORTATTRIBSET��ѯ�����ͨ���ýӿڶ�ȡ�˿���������Ϣ�еĶ˿���״̬
             2.�ϵ��ʼ��ʱ��C��OMͨ���ýӿڻ�ȡ�˿���״̬��֪ͨA��OM���ݶ˿���״̬�����Ƿ�ҽ�HSIC OM��
 �������  : NA

 �������  : penStatus: �˿�״̬
 �� �� ֵ  : SC_ERROR_CODE_ENUM_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��4��3��
    ��    ��   : w00184875
    �޸�����   : ��ʼ����

*****************************************************************************/
extern SC_ERROR_CODE_ENUM_UINT32 SC_FAC_GetPortAttrib(SC_PORT_STATUS_ENUM_UINT32   *penStatus);

/*****************************************************************************
 �� �� ��  : SC_FAC_VerifyPortPassword
 ��������  : NAS�յ�AT^PORTCTRLTMP������øýӿڽ��ж˿�������У��
 �������  : pcPwd: �˿������룬����Ϊ���Ĵ���(����Ϊ16����0��-��9���ַ����)
             ucLen: �˿������볤��

 �������  : NA
 �� �� ֵ  : SC_ERROR_CODE_ENUM_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��4��3��
    ��    ��   : w00184875
    �޸�����   : ��ʼ����

*****************************************************************************/
extern SC_ERROR_CODE_ENUM_UINT32 SC_FAC_VerifyPortPassword(VOS_UINT8 *pucPwd, VOS_UINT8 ucLen);

/*****************************************************************************
 �� �� ��  : SC_PERS_SimlockUnlock
 ��������  : ����Simlock��������
 �������  : enCategory         -- ������������
             *pucPwd            -- ��������
 �������  : ��
 �� �� ֵ  : VOS_OK     -- �����ɹ�
             VOS_ERR    -- ����ʧ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��09��18��
    ��    ��   : l00198894
    �޸�����   : �����ɺ���

*****************************************************************************/
extern VOS_UINT32 SC_PERS_SimlockUnlock(
    SC_PERSONALIZATION_CATEGORY_ENUM_UINT8  enCategory,
    VOS_UINT8                              *pucPwd );

#if ((FEATURE_VSIM == FEATURE_ON) && (FEATURE_OFF == FEATURE_VSIM_ICC_SEC_CHANNEL))
/*****************************************************************************
 �� �� ��  : SC_FAC_SetDhKey
 ��������  : NAS�յ�AT^HVPDH���������ͨ���ýӿڽ�DH KEY�ύ��SC
 �������  : MODEM_ID_ENUM_UINT16         enModemID,
             SC_DH_KEY_TYPE_ENUM_UINT32   enKeyType,
             VOS_UINT32                   ulKeyLen,
             VOS_UINT8                   *pucKey

 �������  : NA
 �� �� ֵ  : SC_ERROR_CODE_ENUM_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2013��8��27��
    ��    ��   : L47619
    �޸�����   : V9R1 vSIM��Ŀ�޸�

*****************************************************************************/
SC_ERROR_CODE_ENUM_UINT32 SC_FAC_SetDhKey(
    MODEM_ID_ENUM_UINT16                enModemID,
    SC_DH_KEY_TYPE_ENUM_UINT32          enKeyType,
    VOS_UINT32                          ulKeyLen,
    VOS_UINT8                          *pucKey
);
#endif

#if (FEATURE_ON != FEATURE_SC_SEC_UPDATE)
/*****************************************************************************
�� �� ��  :SC_COMM_Backup
��������  : SC�ļ����ݴ���
�������  :

�������  :��
�� �� ֵ  :

��������  :
�޶���¼  :
1.��    ��   : 2014��6��5��
  ��    ��   : d00212987
  �޸�����   : ��ʼ����
*****************************************************************************/
VOS_UINT32 SC_COMM_Backup(VOS_VOID);

#if ((OSA_CPU_ACPU == VOS_OSA_CPU))
/*****************************************************************************
�� �� ��  : SC_COMM_Restore
��������  : SC�ļ��ָ�
�������  : ��

�������  : ��
�� �� ֵ  : VOS_UINT32

��������  :
�޶���¼  :
1.��    ��   : 2015��8��10��
  ��    ��   : d00212987
  �޸�����   : SC���ݵ�����NV���ݵ���չ����
*****************************************************************************/
VOS_UINT32 SC_COMM_Restore(VOS_VOID);

#endif

#endif

#if (OSA_CPU_CCPU == VOS_OSA_CPU)
/*****************************************************************************
 �� �� ��  : SC_COMM_CryptoEncPIN
 ��������  : ����PIN�������
 �������  : pucPin  : pin����
             ulPinLen: pin���ĳ���

 �������  : pstCryptoPin:����������Ϣ

 �� �� ֵ  : SC_ERROR_CODE_ENUM_UINT32

  1.��    ��   : 2017��09��07��
    ��    ��   : d00212987
    �޸�����   : PIN����
*****************************************************************************/
SC_ERROR_CODE_ENUM_UINT32 SC_COMM_CryptoEncPIN(
    VOS_UINT8                          *pucPin,
    SC_CRYPTO_PIN_STRU                 *pstCryptoPin
);

/*****************************************************************************
 �� �� ��  : SC_COMM_CryptoDecPIN
 ��������  : ����PIN�������
 �������  : pucPin  : pin����
             ulPinLen: pin���ĳ���

 �������  : pstCryptoPin:����������Ϣ

 �� �� ֵ  : SC_ERROR_CODE_ENUM_UINT32

  1.��    ��   : 2017��09��07��
    ��    ��   : d00212987
    �޸�����   : PIN����
*****************************************************************************/
SC_ERROR_CODE_ENUM_UINT32 SC_COMM_CryptoDecPIN(
    SC_CRYPTO_PIN_STRU                 *pstCryptoPin,
    VOS_UINT8                          *pucPin);

#endif

#if ((VOS_OS_VER == VOS_WIN32) || (VOS_OS_VER == VOS_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif


#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif



