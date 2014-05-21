//
//  LHTMDbClient.m
//  TheMovieDB
//
//  Created by Lukas Herbst on 21.05.14.
//  Copyright (c) 2014 lks.is. All rights reserved.
//

#import "LHTMDbClient.h"

@implementation LHTMDbClient

#pragma mark - Singleton

static LHTMDbClient *_sharedAPIInstance = nil;
static dispatch_once_t onceToken;

+ (instancetype)sharedAPIInstance {
    dispatch_once(&onceToken, ^{
#if DEBUG
        NSURL *url = [NSURL URLWithString:[kLHTMDbAPINoSSL stringByAppendingString:[kLHTMDbAPIBaseURL stringByAppendingString:kLHTMDbAPIVersion]]];
#else
        NSURL *url = [NSURL URLWithString:[kLHTMDbAPISSL stringByAppendingString:[kLHTMDbAPIBaseURL stringByAppendingString:kLHTMDbAPIVersion]]];
#endif
        _sharedAPIInstance = [[self alloc] initWithBaseURL:url];
        _sharedAPIInstance.requestSerializer = [AFJSONRequestSerializer new];
    });
    return _sharedAPIInstance;
}

+ (void)setSharedInstance:(LHTMDbClient *)instance {
    onceToken = 0;
    _sharedAPIInstance = instance;
}

#pragma mark - Public Methods

- (void)GET:(NSString *)service withParameters:(NSDictionary *)parameters andResponseBlock:(LHTMDbClientResponse)block
{
    NSAssert(self.APIKey != nil, @"Please, add your APIKey");
    NSMutableDictionary *keyParameters = parameters ? [parameters mutableCopy] : [@{} mutableCopy];
    NSLog(@"%@", keyParameters);
    keyParameters[@"api_key"] = self.APIKey;
    
    if ([service rangeOfString:@"{id}"].location != NSNotFound)
    {
        if ([service rangeOfString:@"{season_number}"].location !=NSNotFound )
        {
            if ([service rangeOfString:@"{episode_number}"].location !=NSNotFound )
            {
                NSAssert(keyParameters[@"id"] != nil, @"Please, add the id");
                NSAssert(keyParameters[@"season_number"] != nil, @"Please add the season number");
                NSAssert(keyParameters[@"episode_number"] != nil, @"Please add the episode number");
                
                //ID:
                if (![keyParameters[@"id"] isKindOfClass:[NSString class]]) keyParameters[@"id"] = [keyParameters[@"id"] stringValue];
                service = [service stringByReplacingOccurrencesOfString:@"{id}" withString:keyParameters[@"id"]];
                
                //Season Number:
                if (![keyParameters[@"season_number"] isKindOfClass:[NSString class]]) keyParameters[@"season_number"] = [keyParameters[@"season_number"] stringValue];
                service = [service stringByReplacingOccurrencesOfString:@"{season_number}" withString:keyParameters[@"season_number"]];
                
                //Episode Number:
                if (![keyParameters[@"episode_number"] isKindOfClass:[NSString class]]) keyParameters[@"episode_number"] = [keyParameters[@"episode_number"] stringValue];
                service = [service stringByReplacingOccurrencesOfString:@"{episode_number}" withString:keyParameters[@"episode_number"]];
            } else
            {
                NSAssert(keyParameters[@"id"] != nil, @"Please, add the id");
                NSAssert(keyParameters[@"season_number"] != nil, @"Please add the season number");
                
                //ID:
                if (![keyParameters[@"id"] isKindOfClass:[NSString class]]) keyParameters[@"id"] = [keyParameters[@"id"] stringValue];
                service = [service stringByReplacingOccurrencesOfString:@"{id}" withString:keyParameters[@"id"]];
                
                //Season Number:
                if (![keyParameters[@"season_number"] isKindOfClass:[NSString class]]) keyParameters[@"season_number"] = [keyParameters[@"season_number"] stringValue];
                service = [service stringByReplacingOccurrencesOfString:@"{season_number}" withString:keyParameters[@"season_number"]];
            }
        }
        
        NSAssert(keyParameters[@"id"] != nil, @"Please, add the id");
        
        if (![keyParameters[@"id"] isKindOfClass:[NSString class]]) keyParameters[@"id"] = [keyParameters[@"id"] stringValue];
        service = [service stringByReplacingOccurrencesOfString:@"{id}" withString:keyParameters[@"id"]];
    }
    
    [self GET:service parameters:keyParameters success:^(AFHTTPRequestOperation *operation, id responseObject)
    {
        block(responseObject, nil);
    } failure:^(AFHTTPRequestOperation *operation, NSError *error)
    {
        block(nil, error);
    }];
}

@end