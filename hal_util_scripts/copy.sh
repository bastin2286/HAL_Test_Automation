#echo Google@2020 | sudo -S cp -R /var/lib/docker/volumes/taacVolume/_data/workspace/Android_Test/Android_Demo /var/lib/docker/volumes/volAndroidTest/_data/

echo Google@2020 | sudo -S rm -rf /home/318356/HAL_Test_Automation
echo Google@2020 | sudo -S rm -rf /var/lib/docker/volumes/volHAL/_data/HAL_Test_Automation


git clone https://github.com/bastin2286/HAL_Test_Automation.git

echo Google@2020 | sudo -S cp -R /home/318356/HAL_Test_Automation /var/lib/docker/volumes/volHAL/_data/

echo Google@2020 | sudo -S cp -R /home/318356/HAL_Test_Automation/Host_SW/Deploy /var/lib/docker/volumes/volHAL/_data/

echo Google@2020 | sudo -S cp -R /home/318356/HAL_Test_Automation/Host_SW/Test_Scripts /var/lib/docker/volumes/volHAL/_data/

