//
//  GDHNetwokOther.h
//  GDHNetworkDemo
//
//  Created by 高得华 on 16/11/25.
//  Copyright © 2016年 GaoFei. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark ==== 宏定义 =======
// 项目打包上线都不会打印日志，因此可放心。
#ifdef DEBUG
#define DTLog(s, ... ) NSLog( @"[%@ in line %d] ===============>%@", [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, [NSString stringWithFormat:(s), ##__VA_ARGS__] )
#else
#define DTLog(s, ... )
#endif

#define SHOW_ALERT(_msg_)  UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"提示" message:_msg_ delegate:nil cancelButtonTitle:nil otherButtonTitles:@"确定", nil];\
[alert show];


#pragma mark ========= // 枚举 及block \\ ===========
//============== 枚举 ===============
/**
 *  请求类型
 */
typedef NS_ENUM(NSUInteger, GDHNetWorkType) {
    GDHNetWorkTypeGET = 1,   /**< GET请求 */
    GDHNetWorkTypePOST       /**< POST请求 */
};

typedef NS_ENUM(NSUInteger, GDHResponseType) {//响应数据的枚举
    GDHResponseTypeJSON = 1, // 默认
    GDHResponseTypeXML  = 2, // XML
    // 特殊情况下，一转换服务器就无法识别的，默认会尝试转换成JSON，若失败则需要自己去转换
    GDHResponseTypeData = 3,
};

typedef NS_ENUM(NSUInteger, GDHRequestType) {//请求数据的枚举
    GDHRequestTypeJSON = 1, // 默认
    GDHRequestTypePlainText  = 2 // 普通text/html
};

typedef NS_ENUM(NSInteger, GDHNetworkStatus) {//获取网络的枚举
    GDHNetworkStatusUnknown          = -1,//未知网络
    GDHNetworkStatusNotReachable     = 0,//网络无连接
    GDHNetworkStatusReachableViaWWAN = 1,//2，3，4G网络
    GDHNetworkStatusReachableViaWiFi = 2,//WIFI网络
};


//============ blcok ================
/*!
 *
 *  下载进度 get or post
 *
 *  @param bytesRead                 已下载的大小
 *  @param totalBytesRead            文件总大小
 *  @param totalBytesExpectedToRead 还有多少需要下载
 */
typedef void (^GDHDownloadProgress)(int64_t bytesRead,
int64_t totalBytesRead,
int64_t totalBytesExpectedToRead);

typedef GDHDownloadProgress GDHGetProgress;
typedef GDHDownloadProgress GDHPostProgress;

/*!
 *
 *  上传进度
 *
 *  @param bytesWritten              已上传的大小
 *  @param totalBytesWritten         总上传大小
 */
typedef void (^GDHUploadProgress)(int64_t bytesWritten,
int64_t totalBytesWritten);


@class NSURLSessionTask;

// 请勿直接使用NSURLSessionDataTask,以减少对第三方的依赖
// 所有接口返回的类型都是基类NSURLSessionTask，若要接收返回值
// 且处理，请转换成对应的子类类型
typedef NSURLSessionTask GDHURLSessionTask;
typedef void(^GDHResponseSuccess)(id returnData);
typedef void(^GDHResponseFail)(NSError * error);



#pragma mark ========  代理  ================
@protocol GDHNetworkDelegate <NSObject>//请求封装的代理协议

@optional
/**
 *   请求结束
 *
 *   @param returnData 返回的数据
 */
- (void)requestDidFinishLoading:(id)returnData;
/**
 *   请求失败
 *
 *   @param error 失败的 error
 */
- (void)requestdidFailWithError:(NSError*)error;

/**
 *   网络请求项即将被移除掉
 *
 *   @param itme 网络请求项
 */
- (void)netWorkWillDealloc:(GDHURLSessionTask *) itme;

@end
