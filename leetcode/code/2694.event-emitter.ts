/*
 * @lc app=leetcode id=2694 lang=ts
 *
 * [2694]
 */

// @lc code=start

type Callback = (...args: any[]) => any;
type Subscription = {
    unsubscribe: () => void
}

class EventEmitter {
  
    private readonly _map = new Map<string, Set<Callback>>();

    public subscribe(eventName: string, callback: Callback): Subscription {
        
        let set = this._map.get(eventName);
        if (!set) {
            set = new Set();
            this._map.set(eventName, set);
        }

        set.add(callback);

        return {
            unsubscribe: () => {
                set!.delete(callback);
            }
        };
    }

    public emit(eventName: string, args: any[] = []): any[] {
        const results: any[] = [];
        const cb = this._map.get(eventName);
        if (!cb) {
            return results;
        }
        
        for (const callback of cb) {
            results.push(callback(...args));
        }

        return results;
    }
}   

/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */

// @lc code=end
