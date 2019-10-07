def uppercase(str):
    return ''.join([chr(ord(i) - 32) for i in str if ord(i) >= 65])
    
uppercase('hai')
