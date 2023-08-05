type Obj = Record<any, any>;

function compactObject(obj: Obj): Obj {
    if (Array.isArray(obj)) {
        return obj.map(compactObject).filter(Boolean);
    }
    
    for (const prop in obj) {
        const val = obj[prop];

        if (!val) {
            delete obj[prop];
        }

        else if (Array.isArray(val)) {
            obj[prop] = compactObject(val);
        }

        else if (typeof val === 'object' && val !== null) {
            obj[prop] = compactObject(val);
        }
    }

    return obj;
};
