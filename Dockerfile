# Use Ubuntu 22.04 as the base image
FROM ubuntu:22.04

# Set environment variables to non-interactive to avoid prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Update the package list and install necessary packages
RUN apt-get update && \
    apt-get install -y gcc g++ gdb vim make libgtest-dev && \
    apt-get clean

# Set the working directory inside the container
WORKDIR /app

# The default command to run when starting the container
CMD ["/bin/bash"]
