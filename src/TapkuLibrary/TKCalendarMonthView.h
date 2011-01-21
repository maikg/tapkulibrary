//
//  TKCalendarMonthView.h
//  Created by Devin Ross on 6/10/10.
//
/*
 
 tapku.com || http://github.com/devinross/tapkulibrary
 
 Permission is hereby granted, free of charge, to any person
 obtaining a copy of this software and associated documentation
 files (the "Software"), to deal in the Software without
 restriction, including without limitation the rights to use,
 copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the
 Software is furnished to do so, subject to the following
 conditions:
 
 The above copyright notice and this permission notice shall be
 included in all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 OTHER DEALINGS IN THE SOFTWARE.
 
 */
#import <UIKit/UIKit.h>

@class TKCalendarMonthTiles;
@protocol TKCalendarMonthViewDelegate, TKCalendarMonthViewDataSource;


@interface TKCalendarMonthView : UIView {

	TKCalendarMonthTiles *currentTile,*oldTile;
	UIButton *leftArrow, *rightArrow;
	UIImageView *topBackground, *shadow;
	UILabel *monthYear;
	UIScrollView *tileBox;
	BOOL sunday;
    
    NSDate *selectedDate;

	id <TKCalendarMonthViewDelegate> delegate;
	id <TKCalendarMonthViewDataSource> dataSource;

}

@property (nonatomic,assign) id <TKCalendarMonthViewDelegate> delegate;
@property (nonatomic,assign) id <TKCalendarMonthViewDataSource> dataSource;

- (id) initWithSundayAsFirst:(BOOL)sunday; // or Monday


- (NSDate*) dateSelected;
- (NSDate*) monthDate;
- (void) selectDate:(NSDate*)date;
- (void) setMonth:(NSDate *)month animated:(BOOL)animated;
- (void) reload;

@end


@protocol TKCalendarMonthViewDelegate <NSObject>

@optional
- (void) calendarMonthView:(TKCalendarMonthView*)monthView didSelectDate:(NSDate*)d;
- (void) calendarMonthView:(TKCalendarMonthView*)monthView monthDidChange:(NSDate*)d;

@end

@protocol TKCalendarMonthViewDataSource <NSObject>

- (NSArray*) calendarMonthView:(TKCalendarMonthView*)monthView marksFromDate:(NSDate*)startDate toDate:(NSDate*)lastDate;

@end