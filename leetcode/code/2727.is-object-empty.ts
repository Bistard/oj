function isEmpty(obj: Record<string, any> | any[]): boolean {
    if (Array.isArray(obj)) {
        return obj.length === 0;
    }

    for (const _ in obj) {
        return false;
    }

    return true;
};