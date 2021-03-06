#ifndef P2P_DEFINE_H_H_
#define P2P_DEFINE_H_H_

/**
 协议格式Json格式
 <Protocol Start>
 */
#define CMD_START_MARK      "<Protocol Start>"
#define CMD_FINISH_MARK     "<Protocol Finish>"

/**终端到服务端指令**/
/**
 终端到服务端的心跳
 {
     "dataType":"heartbeat_c2s",
     "unique":"终端标识",
     "serial":111,
     "time":"发送时间"

     "clientDesc":"设备描述",
     "ip":"内部ip",
     "port":"内部端口"
 }
 */
#define CMD_C2S_HEARTBEAT "heartbeat_c2s"

/**
 终端请求用户列表
 {
     "dataType":"getUserList",
     "serial":111,
     "unique":"终端标识",
     "time":"发送时间"
 }
 */
#define CMD_C2S_GETCLIENTS "getUserList_c2s"

/**
终端请求连接对端
{
    "dataType":"connectDbg_c2s",
    "dst":"asdf"
}

返回值
{
    "stat":0,               //状态 0：成功 1：失败
    "desc":"abcdef",        //错误描述信息
    "cleintDesc":"xxx"      //调试终端描述
}
*/
#define CMD_C2S_CONNECT "connectDbg_c2s"

/**服务端到终端指令**/
/**
 服务器转发其他用户数据
 {
    "dataType":"transdata_s2c",
    "id":1111,
    "src":"来源终端标识",
    "dst":"目标终端标识",

    "content": {
        "具体的数据内容"
    }
 }
 */
#define CMD_C2S_TRANSDATA "transdata_s2c"

/**
服务端通知终端有新的ftp文件
{
    "dataType":"ftpFileNotify_s2c",
    "ftpUnique":"abcdef"                //ftp文件标识
}
*/
#define CMD_C2S_FTPFILE_NOTIFY  "ftpFileNotify_s2c"

/**终端到终端指令**/
/**
 控制端请求执行命令
 {
     "dataType":"runcmd_c2c",
     "unique":"终端标识",
     "time":"发送时间",

     "cmd":"命令标识",
     "content": {
         ""
     }
 }
 */
#define CMD_C2C_RUNCMD "runcmd_c2c"

/**
 * 终端到终端的心跳
 */
#define CMD_C2C_HEARTBEAT "heartbeat_c2c"

/**
数据回执，所有数据统一以以下格式回执
{
    "dataType":"reply",
    "id":111,
    "stat":0,

    "content":{
        ...
    }
}
*/
#define CMD_REPLY   "reply"

/**文件传输协议**/
/**
文件传输用户注册
{
    "dataType":"ftpRegister",
    "id":1111,
    "unique":"设备标识"
}
*/
#define CMD_FTP_REGISTER    "ftpRegister"

/**
<Protocol Start>
{
    "dataType":"ftpTransfer",
    "id":112233,
    "fileUnique":"文件标识",
    "src":"文件发送方",
    "dst":"文件接收方",
    "desc":"文件描述",
    "fileSize":112233,
    "fileName":"文件名"
}
<Protocol Finish>
具体的文件内容
*/
#define CMD_FTP_TRANSFER   "ftpTransfer"

/**
调试端请求ftp文件
{
    "dataType":"ftpGetFile",
    "id":1122323,
    "ftpUnique":"abcdef"
}
*/
#define CMD_FTP_GETFILE    "ftpGetFile"
#endif
