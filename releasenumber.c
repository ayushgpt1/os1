os_version=$(cat /etc/os-release | grep         PRETTY_NAME | cut -d"=" -f2 | tr -d '"') 
echo "operating system version: $os_version"
os_release=$(cat /etc/os-release | grep         VERSION_ID | cut -d"=" -f2 | tr -d '"') 
echo "release number: $os_release" 
kernel_version=$(uname -r)
echo "release number: $kernel_version" 