class Solution(object):
    def change(self, amount, coins):
        amountList = [0] * (amount + 1)
        amountList[0] = 1
        
        for coinVal in coins:
            for amountVal in range (1, len(amountList)):
                if(amountVal >= coinVal):
                    #print(amountVal, ' ', amountVal - coinVal)
                    amountList[amountVal] += amountList[amountVal - coinVal]
        
        #print(amountList)
        return amountList[amount]
