# Step 1: Change path to source code folder, Dockerfile, source code and binary are here
```bash
     cd ~/rail_fence_algorithm
```
# Step 2: Create docker image
```bash
     sudo docker build -t ubuntu-22.04 .
```

# Step 3: Run docker with image ubuntu-22.04
```bash
     sudo docker run -it ubuntu-22.04
```

# Step 4(Optional): Rebuild the binary
```bash
     make
```

# Step 5: Run test binary to test both encryption and decryption functions
```bash
    # ./test_rail_fence
    <output>
```
# Step 6: Test encryption function manually
```bash
    # ./encryption
    please input the plaintxt:abcdefgh
    please input the depth:2
    please input the repeat:1
    Encrypt the plaintxt with depth 2 and repeat 1 times...
    Plaintxt : abcdefgh
    Chipertxt: acegbdfh
```

# Step 7: Test decryption function manually
```bash
    # ./decryption
    please input the Cipertxt:acegbdfh
    please input the depth:2
    please input the repeat:1
    Decrypt the cipertxt with depth 2 and repeat 1 times...
    Chipertxt : acegbdfh
    Plaintxt: abcdefgh
```
