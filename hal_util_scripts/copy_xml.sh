#!/bin/sh
  
echo Google@2020 | sudo -S cp /var/lib/docker/volumes/volHAL/_data/Test_Scripts/output.xml /var/lib/docker/volumes/volHAL/_data/workspace/HAL_Test_Automation/

echo Google@2020 | sudo chown cloudadmin /var/lib/docker/volumes/volHAL/_data/workspace/HAL_Test_Automation/output.xml

echo Google@2020 | sudo chgrp cloudadmin /var/lib/docker/volumes/volHAL/_data/workspace/HAL_Test_Automation/output.xml

#echo Google@2020 | sudo touch /var/lib/docker/volumes/volHAL/_data/workspace/HAL_Test_Automation/output.xml
