FROM ubuntu:26.04
SHELL ["/bin/bash", "-c"]
MAINTAINER ChristopherPisz
LABEL Description="Chris' Ubuntu based development environment for C++"

ARG USERNAME=developer
ARG USER_UID=1000
ARG USER_GID=1000

# Install all the things we'll need
#    I am installing git on the container rather than the host, because we are using the volume rather than mounting a directory we share with the host
#    in my opinion, doing the latter invites all kinds of problems.
RUN apt update && apt -y --no-install-recommends install \
    sudo \
    bash \
    tree \
    vim \
    git \
    ssh \
    build-essential \
    cmake \
    clang \
    ninja-build \
    gdb \
    wget \
    python3 \
    python3-pip \
    python3-venv \
    apt-transport-https \
    ca-certificates \
    gnupg \
    software-properties-common

# Create a virtual environment for python
RUN python3 -m venv /opt/venv

# Install conan, the package manager for C++ that everyone needs in thier life, in the virtual environment
RUN /opt/venv/bin/pip install conan

# Create a non-root user and give them sudo
RUN existing_user=$(getent passwd $USER_UID | cut -d: -f1) && \
    if [ -n "$existing_user" ] && [ "$existing_user" != "$USERNAME" ]; then \
        usermod -l $USERNAME $existing_user && \
        usermod -d /home/$USERNAME -m $USERNAME; \
    elif ! id -u $USERNAME >/dev/null 2>&1; then \
        useradd --uid $USER_UID --gid $USER_GID -m $USERNAME; \
    fi && \
    echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME && \
    chmod 0440 /etc/sudoers.d/$USERNAME && \
    echo "$USERNAME:$USERNAME" | chpasswd

# Create build directory
RUN mkdir -p /build && chown -R ${USER_UID}:${USER_GID} /build

# Install postgres client and locales
#
# Added towards end of dockerfile so it docker can build the iamge using layers since we are using the same image name as the version of
# devcontainer without postgres
RUN apt install -y postgresql-client \
    locales

RUN locale-gen en_US.UTF-8
ENV LANG en_US.UTF-8
ENV LANGUAGE en_US:en
ENV LC_ALL en_US.UTF-8

# Change to the user
USER $USERNAME
WORKDIR /workspace