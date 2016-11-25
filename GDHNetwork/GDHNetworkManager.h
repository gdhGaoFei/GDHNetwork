//
//  GDHNetworkManager.h
//  GDHNetworking
//
//  Created by 高得华 on 16/10/26.
//  Copyright © 2016年 GaoFei. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GDHNetwokOther.h"
@class GDHNetworkObject;

/// 请求管理着
@interface GDHNetworkManager : NSObject

/**
 *   GET请求通过Block 回调结果
 *
 *   @param url          url
 *   @param paramsDict   paramsDict
 *   @param successBlock  成功的回调
 *   @param failureBlock  失败的回调
 *   @param progress      进度回调
 *  @param refreshCache 是否刷新缓存。由于请求成功也可能没有数据，对于业务失败，只能通过人为手动判断
 *   @param showHUD      是否加载进度指示器
 */
+ (void)getRequstWithURL:(NSString *)url
                  params:(NSDictionary *)paramsDict
            successBlock:(GDHResponseSuccess)successBlock
            failureBlock:(GDHResponseFail)failureBlock
                progress:(GDHGetProgress)progress
            refreshCache:(BOOL)refreshCache
                 showHUD:(BOOL)showHUD;

/**
 *   GET请求通过代理回调
 *
 *   @param url         url
 *   @param paramsDict  请求的参数
 *   @param delegate    delegate
 *   @param progress      进度回调
 *   @param refreshCache 是否刷新缓存。由于请求成功也可能没有数据，对于业务失败，只能通过人为手动判断
 *   @param showHUD    是否转圈圈
 */
+ (void)getRequstWithURL:(NSString*)url
                  params:(NSDictionary*)paramsDict
                delegate:(id<GDHNetworkDelegate>)delegate
                progress:(GDHGetProgress)progress
            refreshCache:(BOOL)refreshCache
                 showHUD:(BOOL)showHUD;
/**
 *   get 请求通过 taget 回调方法
 *
 *   @param url         url
 *   @param paramsDict  请求参数的字典
 *   @param target      target
 *   @param action      action
 *   @param progress      进度回调
 *   @param refreshCache 是否刷新缓存。由于请求成功也可能没有数据，对于业务失败，只能通过人为手动判断
 *   @param showHUD     是否加载进度指示器
 */
+ (void)getRequstWithURL:(NSString*)url
                  params:(NSDictionary*)paramsDict
                  target:(id)target
                  action:(SEL)action
                progress:(GDHGetProgress)progress
            refreshCache:(BOOL)refreshCache
                 showHUD:(BOOL)showHUD;

#pragma mark - 发送 POST 请求的方法
/**
 *   通过 Block回调结果
 *
 *   @param url           url
 *   @param paramsDict    请求的参数字典
 *   @param successBlock  成功的回调
 *   @param failureBlock  失败的回调
 *   @param progress      进度回调
 *   @param refreshCache 是否刷新缓存。由于请求成功也可能没有数据，对于业务失败，只能通过人为手动判断
 *   @param showHUD       是否加载进度指示器
 */
+ (void)postReqeustWithURL:(NSString*)url
                    params:(NSDictionary*)paramsDict
              successBlock:(GDHResponseSuccess)successBlock
              failureBlock:(GDHResponseFail)failureBlock
                  progress:(GDHGetProgress)progress
              refreshCache:(BOOL)refreshCache
                   showHUD:(BOOL)showHUD;
/**
 *   post请求通过代理回调
 *
 *   @param url         url
 *   @param paramsDict  请求的参数
 *   @param delegate    delegate
 *   @param progress      进度回调
 *   @param refreshCache 是否刷新缓存。由于请求成功也可能没有数据，对于业务失败，只能通过人为手动判断
 *   @param showHUD    是否转圈圈
 */
+ (void)postReqeustWithURL:(NSString*)url
                    params:(NSDictionary*)paramsDict
                  delegate:(id<GDHNetworkDelegate>)delegate
                  progress:(GDHGetProgress)progress
              refreshCache:(BOOL)refreshCache
                   showHUD:(BOOL)showHUD;
/**
 *   post 请求通过 target 回调结果
 *
 *   @param url         url
 *   @param paramsDict  请求参数的字典
 *   @param target      target
 *   @param progress      进度回调
 *   @param refreshCache 是否刷新缓存。由于请求成功也可能没有数据，对于业务失败，只能通过人为手动判断
 *   @param showHUD     是否显示圈圈
 */
+ (void)postReqeustWithURL:(NSString*)url
                    params:(NSDictionary*)paramsDict
                    target:(id)target
                    action:(SEL)action
                  progress:(GDHGetProgress)progress
              refreshCache:(BOOL)refreshCache
                   showHUD:(BOOL)showHUD;

@end
