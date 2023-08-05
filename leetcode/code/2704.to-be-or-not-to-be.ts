type ToBeOrNotToBe = {
    toBe: (val: any) => boolean;
    notToBe: (val: any) => boolean;
};

function expect(val: any): ToBeOrNotToBe {
    return {
        toBe: (val1: any) => {
            if (val1 === val) {
                return true;
            }
            throw new Error('Not Equal');
        },
        notToBe: (val1: any) => {
            if (val1 !== val) {
                return true;
            }
            throw new Error('Equal');
        },
    };
};