/*
 * Copyright (c) Meta Platforms, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import "IGTestSingleItemDataSource.h"

#import <IGListKit/IGListSingleSectionController.h>

#import "IGTestCell.h"

@implementation IGTestSingleItemDataSource

- (NSArray *)objectsForListAdapter:(IGListAdapter *)listAdapter {
    return self.objects;
}

- (IGListSectionController *)listAdapter:(IGListAdapter *)listAdapter sectionControllerForObject:(id)object {
    void (^configureBlock)(id, __kindof UICollectionViewCell *) = ^(IGTestObject *item, IGTestCell *cell) {
        cell.label.text = [item.value description];
    };
    CGSize (^sizeBlock)(id, id<IGListCollectionContext>) = ^CGSize(IGTestObject *item, id<IGListCollectionContext> collectionContext) {
        return CGSizeMake([collectionContext containerSize].width, 44);
    };
    return [[IGListSingleSectionController alloc] initWithCellClass:IGTestCell.class
                                                     configureBlock:configureBlock
                                                          sizeBlock:sizeBlock];
}

- (nullable UIView *)emptyViewForListAdapter:(IGListAdapter *)listAdapter {
    return nil;
}

@end
