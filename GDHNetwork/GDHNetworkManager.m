//
//  GDHNetworkManager.m
//  GDHNetworking
//
//  Created by 高得华 on 16/10/26.
//  Copyright © 2016年 GaoFei. All rights reserved.
//

#import "GDHNetworkManager.h"
#import "GDHNetworkObject.h"

@implementation GDHNetworkManager


#pragma mark - GET 请求的三种回调方法
/**
 *   GET请求的公共方法 一下三种方法都调用这个方法 根据传入的不同参数觉得回调的方式
 *
 *   @param url           ur
 *   @param params   paramsDict
 *   @param target       target
 *   @param action       action
 *   @param delegate     delegate
 *   @param successBlock successBlock
 *   @param failureBlock failureBlock
 *   @param progress      进度回调
 *  @param refreshCache 是否刷新缓存。由于请求成功也可能没有数据，对于业务失败，只能通过人为手动判断
 *   @param showHUD      showHUD
 */
+ (void)getRequstWithURL:(NSString*)url
                  params:(NSDictionary*)params
                  target:(id)target
                  action:(SEL)action
                delegate:(id)delegate
            successBlock:(GDHResponseSuccess)successBlock
            failureBlock:(GDHResponseFail)failureBlock
                progress:(GDHGetProgress)progress
            refreshCache:(BOOL)refreshCache
                 showHUD:(BOOL)showHUD
{
    NSMutableDictionary *mutableDict = [NSMutableDictionary dictionaryWithDictionary:params];
    [GDHNetworkObject initWithtype:GDHNetWorkTypeGET url:url params:mutableDict refreshCache:refreshCache delegate:delegate target:target action:action hashValue:0 showHUD:showHUD progress:progress successBlock:successBlock failureBlock:failureBlock];
}


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
                 showHUD:(BOOL)showHUD{
    [self getRequstWithURL:url params:paramsDict target:nil action:nil delegate:nil successBlock:successBlock failureBlock:failureBlock progress:progress refreshCache:refreshCache showHUD:showHUD];
}

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
                 showHUD:(BOOL)showHUD{
    [self getRequstWithURL:url params:paramsDict target:nil action:nil delegate:delegate successBlock:nil failureBlock:nil progress:progress refreshCache:refreshCache showHUD:showHUD];
}
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
                 showHUD:(BOOL)showHUD{
    [self getRequstWithURL:url params:paramsDict target:target action:action delegate:nil successBlock:nil failureBlock:nil progress:progress refreshCache:refreshCache showHUD:showHUD];
}

#pragma mark - 发送 POST 请求的方法

/**
 *   发送一个 POST请求的公共方法 传入不同的回调参数决定回调的方式
 *
 *   @param url           ur
 *   @param params   paramsDict
 *   @param target       target
 *   @param action       action
 *   @param delegate     delegate
 *   @param successBlock successBlock
 *   @param failureBlock failureBlock
 *   @param progress      进度回调
 *   @param refreshCache 是否刷新缓存。由于请求成功也可能没有数据，对于业务失败，只能通过人为手动判断
 *   @param showHUD      showHUD
 */
+ (void)postReqeustWithURL:(NSString*)url
                    params:(NSDictionary*)params
                    target:(id)target
                    action:(SEL)action
                  delegate:(id<GDHNetworkDelegate>)delegate
              successBlock:(GDHResponseSuccess)successBlock
              failureBlock:(GDHResponseFail)failureBlock
                  progress:(GDHGetProgress)progress
              refreshCache:(BOOL)refreshCache
                   showHUD:(BOOL)showHUD
{
    NSMutableDictionary *mutableDict = [NSMutableDictionary dictionaryWithDictionary:params];
    [GDHNetworkObject initWithtype:GDHNetWorkTypePOST url:url params:mutableDict refreshCache:refreshCache delegate:delegate target:target action:action hashValue:1 showHUD:showHUD progress:progress successBlock:successBlock failureBlock:failureBlock];
}

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
                   showHUD:(BOOL)showHUD{
    [self postReqeustWithURL:url params:paramsDict target:nil action:nil delegate:nil successBlock:successBlock failureBlock:failureBlock progress:progress refreshCache:refreshCache showHUD:showHUD];
}
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
                   showHUD:(BOOL)showHUD{
    [self postReqeustWithURL:url params:paramsDict target:nil action:nil delegate:delegate successBlock:nil failureBlock:nil progress:progress refreshCache:refreshCache showHUD:showHUD];
}
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
                   showHUD:(BOOL)showHUD{
    [self postReqeustWithURL:url params:paramsDict target:target action:action delegate:nil successBlock:nil failureBlock:nil progress:progress refreshCache:refreshCache showHUD:showHUD];
}


@end
