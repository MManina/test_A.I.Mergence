import os
import random

def create_file(name):
    # Open file
    file = open(name, 'w')
    # Generate n block of 512 bytes
    nb_bloc = 10 
    text = ''
    for i in range(nb_bloc * 1024):
        text+=chr(random.randrange(48,126))
        #text+=chr(int(i/1024)+48)
    # Write it into file
    file.write(text)

# Remove old data:
os.system('rm -rf ./data/*')
# Generate new data
create_file('data.txt')