//
//  GDHAsiNetworkDefine.h
//  GDHNetworking
//
//  Created by 高得华 on 16/10/26.
//  Copyright © 2016年 GaoFei. All rights reserved.
//

#ifndef GDHAsiNetworkDefine_h
#define GDHAsiNetworkDefine_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
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

//正式库 上架时需要URL
static NSString * const baseURL = @"http://op.juhe.cn/";

//测试库 调试时需要URL
//static NSString * const baseURL = @"http://op.juhe.cn/";

#endif /* GDHAsiNetworkDefine_h */
