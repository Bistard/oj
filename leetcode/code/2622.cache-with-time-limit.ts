
class TimeLimitedCache {
    
    private readonly _cache: Map<number, number>;
    private readonly _duration: Map<number, any>;
    
    constructor() {
        this._cache = new Map();
        this._duration = new Map();
    }

    private __updateDuration(key: number, duration: number) {
        const existed = this._duration.get(key);
        if (existed) {
            clearTimeout(existed);
        }

        const token = setTimeout(() => {
            this._cache.delete(key);
            this._duration.delete(key);
        }, duration);

        this._duration.set(key, token);
    }

    set(key: number, value: number, duration: number): boolean {
        const existed = this._cache.get(key);
        
        this._cache.set(key, value);
        this.__updateDuration(key, duration);

        return existed !== undefined ? true : false;
    }

    get(key: number): number {
        const value = this._cache.get(key);
        return value !== undefined ? value : -1;
    }

	count(): number {
        return this._cache.size;
    }
}

/**
 * Your TimeLimitedCache object will be instantiated and called as such:
 * var obj = new TimeLimitedCache()
 * obj.set(1, 42, 1000); // false
 * obj.get(1) // 42
 * obj.count() // 1
 */