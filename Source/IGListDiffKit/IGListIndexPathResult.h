/*
 * Copyright (c) Meta Platforms, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <Foundation/Foundation.h>

#import "IGListMoveIndexPath.h"

NS_ASSUME_NONNULL_BEGIN

/**
 A result object returned when diffing with sections.
 */
NS_SWIFT_NAME(ListIndexPathResult)
@interface IGListIndexPathResult : NSObject

/**
 The index paths inserted into the new collection.
 */
@property (nonatomic, copy, readonly) NSArray<NSIndexPath *> *inserts;

/**
 The index paths deleted from the old collection.
 */
@property (nonatomic, copy, readonly) NSArray<NSIndexPath *> *deletes;

/**
 The index paths in the old collection that need updated.
 */
@property (nonatomic, copy, readonly) NSArray<NSIndexPath *> *updates;

/**
 The moves from an index path in the old collection to an index path in the new collection.
 */
@property (nonatomic, copy, readonly) NSArray<IGListMoveIndexPath *> *moves;

/**
 A Read-only boolean that indicates whether the result has any changes or not.
 `YES` if the result has changes, `NO` otherwise.
 */
@property (nonatomic, assign, readonly) BOOL hasChanges;

/**
 Returns the index path of the object with the specified identifier *before* the diff.

 @param identifier The diff identifier of the object.

 @return The index path of the object before the diff, or `nil`.

 @see `-[IGListDiffable diffIdentifier]`.
 */
- (nullable NSIndexPath *)oldIndexPathForIdentifier:(id<NSObject>)identifier;

/**
 Returns the index path of the object with the specified identifier *after* the diff.

 @param identifier The diff identifier of the object.

 @return The index path of the object after the diff, or `nil`.

 @see `-[IGListDiffable diffIdentifier]`.
 */
- (nullable NSIndexPath *)newIndexPathForIdentifier:(id<NSObject>)identifier;

/**
 Creates a new result object with operations safe for use in `UITableView` and `UICollectionView` batch updates.
 */
- (IGListIndexPathResult *)resultForBatchUpdates;

/**
 :nodoc:
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 :nodoc:
 */
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
