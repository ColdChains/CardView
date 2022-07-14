//
//  ViewController.m
//  LCCardView
//
//  Created by lax on 2022/5/20.
//

#import "ViewController.h"
#import <Masonry/Masonry.h>
#import "LCCardView.h"
#import "LCPageControl.h"

@interface ViewController () <LCCardViewDelegate, LCCardViewDataSource>

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // 卡片效果
    LCCardView *cardView = [[LCCardView alloc] init];
    cardView.delegate = self;
    cardView.dataSource = self;
    cardView.edgeInsets = UIEdgeInsetsMake(0, 18, 0, 18);
    cardView.minSpacing = 12;
    cardView.canLoop = NO;
    cardView.tag = 100;
    
    [self.view addSubview:cardView];
    [cardView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.right.mas_equalTo(0);
        make.top.mas_equalTo(88);
        make.height.mas_equalTo(100);
    }];
    
    // 轮播图效果
    LCCardView *bannerView = [[LCCardView alloc] init];
    bannerView.delegate = self;
    bannerView.dataSource = self;
    bannerView.edgeInsets = UIEdgeInsetsMake(0, 18, 0, 18);
    bannerView.minSpacing = 12;
    bannerView.canLoop = YES;
    
    LCPageControl *control = [[LCPageControl alloc] init];
    control.backgroundColor = [UIColor lightGrayColor];
    control.pageIndicatorTintColor = [UIColor redColor];
    control.currentPageIndicatorTintColor = [UIColor whiteColor];
    control.delegate = bannerView;
    bannerView.pageControl = control;
    
    [self.view addSubview:bannerView];
    [bannerView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.right.mas_equalTo(0);
        make.top.mas_equalTo(cardView.mas_bottom).offset(44);
        make.height.mas_equalTo(333);
    }];
}

// 返回card数量
- (NSInteger)numberOfItemsInCardView:(LCCardView *)cardView {
    return cardView.tag == 100 ? 10 : 3;
}

// 返回card大小
- (CGSize)sizeForItemInCardView:(LCCardView *)cardView {
    return cardView.tag == 100 ? CGSizeMake(100, 100) : CGSizeMake(UIScreen.mainScreen.bounds.size.width - 18 * 2, 333);
}

// 返回card样式
- (UIView *)cardView:(LCCardView *)cardView cellForItemAtIndex:(NSInteger)index {
    UIImageView *cell = (UIImageView *)[cardView dequeueReusableCell];
    if (!cell) {
        cell = [[UIImageView alloc] init];
    }
    cell.backgroundColor = @[[UIColor greenColor], [UIColor orangeColor], [UIColor redColor]][index % 3];
    return cell;
}

// 点击card
- (void)cardView:(LCCardView *)cardView didSelectItemAtIndex:(NSInteger)index {
    NSLog(@"%ld", index);
}

@end
