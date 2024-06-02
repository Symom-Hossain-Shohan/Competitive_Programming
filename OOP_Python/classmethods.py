import csv


class item:
    # class level attribute
    pay_rate = 0.8
    all = []
    def __init__(self, name: str, price = 0, quantity=0):
        # Run validations to the received arguments 
        assert price >=0, f"price {price} is not greater than zero!"
        assert quantity >=0, f"quantity {quantity} is not greater than zero!"

        # Assign to self object
        # instance level attribute
        self.name = name
        self.price = price
        self.quantity = quantity
        # print(f"An instance of {name}")

        # Saving all the instances in a list
        item.all.append(self)
    
    def calculate_total(self):
        return self.price * self.quantity
    
    def __repr__(self):
        return f"item('{self.name}', {self.price}, {self.quantity})"
    # items = []
    @classmethod
    def initialize_from_csv(cls):
        with open('data.csv', 'r') as f:
            reader = csv.DictReader(f)
            items = list(reader)
        
        for it in itmes:
            item(
                name = it.get('name'), 
                price = it.get('price'), 
                quantity = it.get('quantity')
            )


# item1 = item("Phone", 100, 5)
# item2 = item("Laptop", 400, 2)
# item3 = item("Calculator", 40, 5)
# item4 = item("Tab", 90, 5)

# print(item1.calculate_total())

print(item.all)

