//
//  LCCardView.h
//  LC
//
//  Created by lax on 2022/1/26.
//

#import <UIKit/UIKit.h>
#import "LCCardScrollView.h"
#import "LCPageControlDelegate.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, LCCardViewOrientation) {
    LCCardViewOrientationHorizontal = 0, // 横向
    LCCardViewOrientationVertical // 竖向
};

typedef NS_ENUM(NSInteger, LCCardViewAlignment) {
    LCCardViewAlignmentLeft = 0, // 居左
    LCCardViewAlignmentCenter, // 居中
    LCCardViewAlignmentRight // 居右
};


@class LCCardView;


@protocol LCCardViewDelegate <NSObject, UIScrollViewDelegate>

@optional

// 返回cell的大小
- (CGSize)sizeForItemInCardView:(LCCardView *)cardView;

// 点击某个cell
- (void)cardView:(LCCardView *)cardView didSelectItemAtIndex:(NSInteger)index;

@end


@protocol LCCardViewDataSource <NSObject>

// 返回Cell的数量
- (NSInteger)numberOfItemsInCardView:(LCCardView *)cardView;

// 返回Cell
- (UIView *)cardView:(LCCardView *)cardView cellForItemAtIndex:(NSInteger)index;

@end


@interface LCCardView : UIView <UIScrollViewDelegate, LCPageControlDelegate>

// 代理
@property (nonatomic, weak) id <LCCardViewDelegate> delegate;

// 数据源
@property (nonatomic, weak) id <LCCardViewDataSource> dataSource;

// 滚动视图
@property (nonatomic, strong, readonly) LCCardScrollView *scrollView;

// 总页数
@property (nonatomic, assign, readonly) NSInteger numberOfItems;

// 当前页数
@property (nonatomic, assign, readonly) NSInteger currentIndex;

// 一页的大小
@property (nonatomic, assign, readonly) CGSize itemSize;

// 滚动方向 默认横向
@property (nonatomic) LCCardViewOrientation orientation;

// 当前卡片的位置 默认居左
@property (nonatomic) LCCardViewAlignment alignment;

// 是否开启无限轮播 默认NO
@property (nonatomic) BOOL canLoop;

// 是否开启自动滚动 默认NO
@property (nonatomic) BOOL autoScroll;

// 自动切换视图的时间 默认5s
@property (nonatomic) NSTimeInterval autoScrollTimeInterval;

// 一次滑动的页数 默认1
@property (nonatomic) NSInteger scrollNumber;

// 内边距 默认0
@property (nonatomic) UIEdgeInsets edgeInsets;

// 最小Cell的间距 默认0
@property (nonatomic) CGFloat minSpacing;

// 最小Cell的比例 默认1
@property (nonatomic) CGFloat minScale;

// 最小Cell的透明度 默认1
@property (nonatomic) CGFloat minAlpha;

// 指示器
@property (nonatomic, strong) UIView<LCPageControlDelegate> *pageControl;

// 调整指示器的位置(Top无效 pageControl以bottom和height设置约束)
@property (nonatomic) UIEdgeInsets pageControlEdgeInsets;

// 刷新视图
- (void)reloadData;

// 获取可重复使用的Cell
- (UIView *)dequeueReusableCell;

// 滚动到下一个
- (void)scrollToNextItem;

// 滚动到指定的Cell
- (void)scrollToItemAtIndex:(NSInteger)index animated:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END
