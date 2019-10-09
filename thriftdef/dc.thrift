//thrift  server and client interface

##################################typedef###############################
//类型别名
typedef i32 int
typedef i16 short
typedef i64 long
###################################struct##############################
//结构体定义
struct user {
   1: string name
}

//传输文件定义
struct FileData
{
    1:required string   name,                   // 文件名字
    2:required binary   buff,                   // 文件数据
}
####################################servic#############################
//服务接口定义
service datecService
{
     string stringInfo(1:string s)     //发送字符串
     oneway void heart(1:string s)       //心跳
     
}
service FileInfoExtractService
{
     bool uploadFile(1:FileData filedata);       // 文件解析函数
}