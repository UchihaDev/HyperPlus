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
  �� �� ��   : ScCommCtx.c
  �� �� ��   : ����
  ��    ��   : d00212987
  ��������   : 2015��08��10��
  ����޸�   :
  ��������   : SC CONTEXT�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2015��08��10��
    ��    ��   : d00212987
    �޸�����   : �����ļ�

******************************************************************************/

/*****************************************************************************
  1 ͷ�ļ�����
*****************************************************************************/
#include "ScCommCtx.h"


#define THIS_FILE_ID PS_FILE_ID_SC_CONTEXT_C

/*****************************************************************************
  2 ȫ�ֱ�������
*****************************************************************************/

/*****************************************************************************
 ȫ�ֱ�����    : g_stScCtx
 ȫ�ֱ���˵��  : SC����������
 1.��    ��   : 2012��04��19��
   ��    ��   : w00184875
   �޸�����   : �½�

  2.��    ��   : 2016��05��07��
    ��    ��   : d00212987
    �޸�����   : ���������㷨������Ŀ�޸�
*****************************************************************************/
static SC_CONTEXT_STRU                  g_stScCtx = {
    /* SC_COMM_GLOBAL_VAR */
    {
        {
            "/modem_secure/SC/Pers/CKFile.bin",
            "/modem_secure/SC/Pers/DKFile.bin",
            "/modem_secure/SC/Pers/AKFile.bin",
            "/modem_secure/SC/Pers/PIFile.bin",
            "/modem_secure/SC/Pers/ImeiFile_I0.bin",
            "/modem_secure/SC/Pers/ImeiFile_I1.bin",
            "/modem_secure/SC/Pers/ImeiFile_I2.bin",
            "/modem_secure/SC/Pers/PI_ECPFile.bin",
            "/modem_secure/SC/Pers/CK_ECPFile.bin",
        },
        {
            "/modem_secure/SC/Pers/CKSign.hash",
            "/modem_secure/SC/Pers/DKSign.hash",
            "/modem_secure/SC/Pers/AKSign.hash",
            "/modem_secure/SC/Pers/PISign.hash",
            "/modem_secure/SC/Pers/ImeiFile_I0.hash",
            "/modem_secure/SC/Pers/ImeiFile_I1.hash",
            "/modem_secure/SC/Pers/ImeiFile_I2.hash",
            "/modem_secure/SC/Pers/PI_ECPFile.hash",
            "/modem_secure/SC/Pers/CK_ECPFile.hash",
        }
    },
    /* SC_FAC_GLOBAL_VAR */
    {
        SC_AUTH_STATUS_UNDO,
        "",
        VOS_FALSE,
        ""
    }
};

/*****************************************************************************
  3 ����ʵ��
*****************************************************************************/

/*****************************************************************************
 �� �� ��  : SC_CTX_GetScCtxAddr
 ��������  : ��ȡ��ǰSC��CTX
 �������  : ��
 �������  : ��
 �� �� ֵ  : ���ص�ǰSC��CTX��ַ
 ���ú���  :
 ��������  :

 �޸���ʷ      :
 1.��    ��   : 2012��04��20��
   ��    ��   : w00184875
   �޸�����   : �����ɺ���

*****************************************************************************/
SC_CONTEXT_STRU* SC_CTX_GetScCtxAddr(VOS_VOID)
{
    return &(g_stScCtx);
}

/*****************************************************************************
 �� �� ��  : SC_CTX_GetCommGlobalVarAddr
 ��������  : ��ȡSC����������ȫ�ֱ�����ַ
 �������  : ��
 �������  : ��
 �� �� ֵ  : SC����������ȫ�ֱ���������ָ��
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��04��19��
    ��    ��   : w00184875
    �޸�����   : �����ɺ���
*****************************************************************************/
SC_COMM_GLOBAL_STRU*  SC_CTX_GetCommGlobalVarAddr( VOS_VOID )
{
    return &g_stScCtx.stScCommGlobalVar;
}


