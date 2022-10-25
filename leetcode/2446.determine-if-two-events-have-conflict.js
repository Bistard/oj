/*
 * @lc app=leetcode id=2446 lang=javascript
 *
 * [2446] Determine if Two Events Have Conflict
 */

// @lc code=start

/**
 * @param {string[]} event1
 * @param {string[]} event2
 * @return {boolean}
 */
var haveConflict = function(event1, event2) {
    let [start1, end1] = event1;
    let [start2, end2] = event2;
    
    start1 = toTime(start1);
    start2 = toTime(start2);
    end1 = toTime(end1);
    end2 = toTime(end2);

    if (start1 > start2) {
        return haveConflict(event2, event1);
    }

    // default event1 is first event
    if (end1 >= start2) {
        return true;
    }

    return false;
};

var toTime = function (time) {
    let [hr, min] = time.split(':');
    return parseInt(hr) * 100 + parseInt(min);
}

// @lc code=end
