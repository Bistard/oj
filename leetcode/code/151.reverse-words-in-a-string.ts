function reverseWords(s: string): string {
    const words = s.split(' ').filter(str => str != '');
    return words.reverse().join(' ');
};