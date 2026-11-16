def fractional_knapsack(capacity, weights, profits):

    n = len(weights)

    ratio = []

    for i in range(n):
        ratio.append(profits[i] / weights[i])

    items = sorted(zip(weights, profits, ratio),
                   key=lambda x: x[2], reverse=True)

    total_profit = 0

    print("\nSelected Items:")

    for weight, profit, r in items:

        if capacity == 0:
            break

        if weight <= capacity:
            capacity -= weight
            total_profit += profit

            print("Weight:", weight, "Profit:", profit)

        else:
            fraction = capacity / weight
            total_profit += profit * fraction

            print("Weight:", capacity,
                  "Fraction:", fraction)

            capacity = 0

    return total_profit


# Main program
capacity = int(input("Enter knapsack capacity: "))

n = int(input("Enter number of items: "))

weights = []
profits = []

for i in range(n):
    w = int(input("Enter weight: "))
    p = int(input("Enter profit: "))

    weights.append(w)
    profits.append(p)

result = fractional_knapsack(capacity, weights, profits)

print("\nMaximum Profit:", result)