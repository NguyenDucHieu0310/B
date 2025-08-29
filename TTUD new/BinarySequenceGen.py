def Gen(n):
    def backtrack(cur):
        if(len(cur)==n):
            print(cur)
            return
        backtrack(cur+'0')
        backtrack(cur+'1')
    backtrack('')
Gen(n=int(input()))
        