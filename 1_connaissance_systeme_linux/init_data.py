import os
import random

def create_file(name):
    # Open file
    file = open(name, 'w')
    # Generate n block of 512 bytes
    nb_bloc = random.randrange(1,5)
    text = ''
    for i in range(nb_bloc * 512):
        text+=chr(random.randrange(48,126))
    # Write it into file
    file.write(text)

def create_folders(level, directory, n=2):
    # Generate n files / folders
    if(n == 2): n = random.randrange(2,25)
    for i in range(n):
        if(level<2):
            # Choose if we create folder
            create_folder =  random.randrange(0,3)
            if(create_folder == 0):
                new_level = level + 1
                new_directory = directory + str(i) + '/'
                if(not os.path.isdir(new_directory)):os.mkdir(new_directory)
                create_folders(new_level, new_directory)
        # Create file
        create_file(directory+str(i)+'.txt')

# Remove old data:
os.system('rm -rf ./data/*')
# Generate new data
create_folders(0, './data/', 10)