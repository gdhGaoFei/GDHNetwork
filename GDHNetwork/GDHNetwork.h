//
//  GDHNetwork.h
//  GDHNetworking
//
//  Created by 高得华 on 16/10/26.
//  Copyright © 2016年 GaoFei. All rights reserved.
//

#ifndef GDHNetwork_h
#define GDHNetwork_h

// 项目打包上线都不会打印日志，因此可放心。
#ifdef DEBUG
#define DTLog(s, ... ) NSLog( @"[%@ in line %d] ===============>%@", [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, [NSString stringWithFormat:(s), ##__VA_ARGS__] )
#else
#define DTLog(s, ... )
#endif

#define SHOW_ALERT(_msg_)  UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"提示" message:_msg_ delegate:nil cancelButtonTitle:nil otherButtonTitles:@"确定", nil];\
[alert show];

#import "GDHAsiNetworkDefine.h"
#import "GDHNetworkManager.h"
#import "GDHNetworkObject.h"
#import "MBProgressHUD+Add.h"
#import "MBProgressHUD.h"

#endif /* GDHNetwork_h */
