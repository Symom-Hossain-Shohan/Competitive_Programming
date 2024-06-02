class item: 
    def calculate_total(self, x, y):
        return x*y
    

item1, item2 = item(), item()

item1.price = 100
item1.quantity = 5
item1.name = "Phone"

print(item1.calculate_total(item1.price, item1.quantity))