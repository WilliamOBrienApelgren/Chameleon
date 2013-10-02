//
//  UIStoryboardSegue.h
//  UIKit
//
//  Created by Derek van Vliet on 2013-10-02.
//
//

#import <Foundation/Foundation.h>

@class UIViewController;

@interface UIStoryboardSegue : NSObject

+ (id)segueWithIdentifier:(NSString *)identifier source:(UIViewController *)source destination:(UIViewController *)destination performHandler:(void (^)(void))performHandler;

- (id)initWithIdentifier:(NSString *)identifier source:(UIViewController *)source destination:(UIViewController *)destination;

@property (nonatomic, readonly) NSString *identifier;
@property (nonatomic, readonly) id sourceViewController;
@property (nonatomic, readonly) id destinationViewController;

- (void)perform;

@end
