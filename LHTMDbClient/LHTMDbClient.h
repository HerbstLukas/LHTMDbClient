//
//  LHTMDbClient.h
//  TheMovieDB
//
//  Created by Lukas Herbst on 21.05.14.
//  Copyright (c) 2014 lks.is. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AFHTTPRequestOperationManager.h"
#import "LHTMDbClientDefines.h"

typedef void (^LHTMDbClientResponse)(id response, NSError *error);

@interface LHTMDbClient : AFHTTPRequestOperationManager

@property (copy, nonatomic) NSString *APIKey;

#pragma mark - Public Methods

/**
 *  Runs an AFHTTPRequestOperation, GET request.
 *
 *  @param service    The service to be sent according to the client request
 *  @param parameters The parameters to be encoded according to the client service request, it can be nil.
 *  @param block      A block object to be executed when the request finishes successfully or unsuccessfully.
 */

- (void)GET:(NSString *)service withParameters:(NSDictionary *)parameters andResponseBlock:(LHTMDbClientResponse)block;

#pragma mark - Singleton

/**
 *  Returns a singleton LHTMDbClient
 *
 *  @return instancetype
 */
+ (instancetype)sharedAPIInstance;

/**
 *  A hook to override singleton, used only for testing purposes
 *
 *  @param instance LHTMDbClient to override
 */

+ (void)setSharedInstance:(LHTMDbClient *)instance;

@end