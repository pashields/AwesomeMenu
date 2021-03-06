//
//  AwesomeMenu.h
//  AwesomeMenu
//
//  Created by Levey on 11/30/11.
//  Copyright (c) 2011 Levey & Other Contributors. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AwesomeMenuItem.h"

@protocol AwesomeMenuDelegate;


@interface AwesomeMenu : UIView <AwesomeMenuItemDelegate>
{
    NSArray *_menusArray;
    int _flag;
    NSTimer *_timer;
    
    id<AwesomeMenuDelegate> _delegate;
    BOOL _isAnimating;
}
@property (nonatomic, copy) NSArray *menusArray;
@property (nonatomic, retain) AwesomeMenuItem *addButton;
@property (nonatomic, getter = isExpanding) BOOL expanding;
@property (nonatomic, assign) id<AwesomeMenuDelegate> delegate;

@property (nonatomic, retain) UIImage *image;
@property (nonatomic, retain) UIImage *highlightedImage;
@property (nonatomic, retain) UIImage *contentImage;
@property (nonatomic, retain) UIImage *highlightedContentImage;

@property (nonatomic, assign) CGFloat nearRadius;
@property (nonatomic, assign) CGFloat endRadius;
@property (nonatomic, assign) CGFloat farRadius;
@property (nonatomic, assign) CGPoint startPoint;
@property (nonatomic, assign) CGFloat timeOffset;
@property (nonatomic, assign) CGFloat rotateAngle;
@property (nonatomic, assign) CGFloat menuWholeAngle;
@property (nonatomic, assign) CGFloat expandRotation;
@property (nonatomic, assign) CGFloat closeRotation;
@property (nonatomic, assign) CGFloat addButtonAngle;

@property (nonatomic, assign) BOOL shouldRotateMenuItems;
@property (nonatomic, assign) BOOL shouldRotateRootItem;
@property (nonatomic, assign) NSTimeInterval animationDuration;

- (id)initWithFrame:(CGRect)frame;
- (void)close;
- (void)expand;
@end

@protocol AwesomeMenuDelegate <NSObject>
@optional
- (void)AwesomeMenuWillExpand:(AwesomeMenu *)menu;
- (void)AwesomeMenuDidShrink:(AwesomeMenu *)menu;
- (void)AwesomeMenu:(AwesomeMenu *)menu didSelectIndex:(NSInteger)idx;
@end