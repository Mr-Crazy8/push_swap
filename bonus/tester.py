import random
import os
import time  # Import the time module for sleep

# def tester(min, max):
#     numbers = []
#     while len(numbers) < max:
#         i = random.randint(-213648, 213647)
#         if i not in numbers:
#             numbers.append(i)
#     p = ' '.join(map(str, numbers))
#     out = os.popen(f"./push_swap {p} | wc -l && sleep 0.3").read()
#     print(out)

# while True:
#     tester(0, 500)
# import random
# import os
# import time  # Import the time module for sleep

def tester(min, max):
    numbers = []
    while len(numbers) < max:
        i = random.randint(-213648, 213647)
        if i not in numbers:
            numbers.append(i)
    p = ' '.join(map(str, numbers))
    out = os.popen(f"./a.out {p} | wc -l").read()
    return int(out.strip()) 


results = []

try:
    while True:
        result = tester(0, 500)
        results.append(result)  
        print(result) 
        time.sleep(0.3)  
except KeyboardInterrupt:
   
    if results:
        min_result = min(results)  
        max_result = max(results) 
        print(f"The max is: {max_result}")
        print(f"The min is: {min_result}")
    else:
        print("No results")
