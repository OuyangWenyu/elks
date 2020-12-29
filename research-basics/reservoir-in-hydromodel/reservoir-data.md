# Reservoir data

## Global monitoring of large reservoir storage from satellite remote sensing (2012)

观测34个大水库，有表面高程数据，从MODIS卫星数据可以得到面积数据，进而推求出高程面积关系。进而还推求了库容变化数据。

具体信息待补充。

## A novel algorithm for monitoring reservoirs under all-weather conditions at a high temporal resolution through passive microwave remote sensing (2016)

Huilin Gao老师又一篇分析水库库容的文章，通过被动微波遥感数据分析能获取所有气象条件下的4天一个步长的水库库容数据。

## High-resolution mapping of global surface water and its long-term changes (2016)

这是nature一篇分析全球水面长期变化数据的文章。使用了300万张landsat图片，在30m分辨率上分析了 1984－2015 32年的地表水变化。月尺度和年尺度的数据。数据集可能后续用得上。

## Satellite Remote Sensing for Water Resources Management （2018）

这篇文章Satellite Remote Sensing for Water Resources Management: Potential for Supporting Sustainable Development in Data-Poor Regions介绍了很多现在正在WRM中用的，可以用的以及将来可能会用到的遥感数据，并阐述了益处和面临的问题。

首先，是**Data needs for WRM**。

主要参考原文table1。个人觉得比较不错，因此copy一遍。

|水资源管理决策|用于决策的水相关数据|传统数据源|
|-|-|-|
|**规划设计**|-|-|
|防洪|降雨径流长期记录，cold regions长期SWE|雨量站、径流站网，snow courses and pillows|
|水电系统|径流长期记录，cold regions长期SWE|同上|
|灌溉系统|降雨、径流和地下水长期记录，crop用水估计|雨量站、径流站网，wells、piezometers，气象网|
|污水处理系统|径流、地下水等的feed sources的记录|径流站网，wells、piezometers|
|供水系统|降雨径流和地下水记录|雨量站、径流站网；wells、piezometers|
|跨境水|长期径流和地下水记录，用水记录|径流站网，wells、piezometers|
|**管理运行**|-|-|
|水资源管理（满足需水）|实时降水、蒸发、径流和地下水|雨量站网，eddy-covariance towers, 径流站网， wells、piezometers|
|供水调度（保证可靠性）|实时降水、蒸发和地下水|同上|
|水电调度|实时降水、蒸发、径流、降水预报|雨量站，径流站，气象站，天气预报|
|防洪调度|实时降水、径流和SWE、降水预报|雨量站，径流站，snow courses and pillows，天气预报|
|污水管理|实时径流和地下水数据|径流站，wells、piezometers|
|灌溉系统调度|实时降水、径流、地下水和土壤含水量，蒸发估计|雨量站、径流站网，wells、piezometers，土壤含水量probes，eddy-covariance towers，气象站|
|生态系统管理|近期降水、径流、水位、土壤含水量和水质数据|雨量站、径流站、水位站、水质采样|
|**灾害管理**|-|-|
|crop监测和粮食安全|实时vegetation特征、crop需水、土壤含水量、降水预报|田间crop采样，eddy-covariance towers，气象站，土壤含水量probes，天气预报|
|干旱早期预警和管理|实时降水、土壤含水量、径流、地下水、降水预报|雨量站，土壤含水量probes，径流站，wells、piezometers，天气预报|
|洪水早期预警和管理|实时降水，径流和降水预报|雨量站、径流站、天气预报|
|水健康|实时降水、地表水和水质参数|雨量站、径流站、水位站、水质采样|

table2总结了**WRM需要的变量以及数据源**，也copy一遍。

|变量|数据源|空间覆盖|时间覆盖|Utility for WRM|
|-|-|-|-|-|
|**降水**|测站网|国家测站网|年到几十年；实时受限|必要，但是实时和空间覆盖上可用性受限|
||遥感|极地外全球|10-15年亚日尺度数据，近实时|在站点稀疏地区必要，但受限于较大不确定性和短时间范围|
||模型|区域到全球|可变，近实时|全球和几十年的范围但较大不确定性|
|**ET,PET**|测站网（pan PET）|国家测网|年到几十年|对评价crop需水有必要|
||Flux towers（ET）|有限测点|1-10年|数量有限，空间代表性有限，主要用于验证|
||遥感（ET,PET）|区域到全球|几十年，近实时|全球和几十年的范围但较大不确定性|
||模型（ET,PET）|区域到全球|几十年，近实时|全球和几十年的范围但较大不确定性，需要前提知识|
|**径流**|测站网|国家测站网|几十年，近实时|必要，但很多地区不可用|
||遥感|仅大河|年到几十年，实时性有限|较大不确定性，范围有限，但可用处还是必要的|
||模型|区域到全球|几十年，近实时|在无观测地区只能用它，有很大不确定性，代表性差|
|**水位**|测站网|特定水体|年到十年，实时性有限|必要但是许多地区没有|
||遥感|受限于大河和水体|年到十年，实时|范围有限，但对特定水体有用|
||模型||几十年，近实时|较大不确定性但在许多地方是唯一数据源|
|**土壤含水量**|测站网|有限空间覆盖|年，实时性有限|对局部应用有用，用作验证很有必要|
||遥感|全球|年到几十年，近实时|有限深度，但是如果和模型结合很有用|
||模型|全球|几十年，近实时|较大不确定性，但是对干旱应用有用|
|**雪和冰**|测站网|区域的|年到几十年，一些站点近实时|测站较密是有必要||
||遥感|全球|年到几十年，近实时|必要，但是SWE有较大不确定性，对snow covered地区更准确|
||模型|全球|几十年，近实时|较大不确定性，但是可以和in-situ及遥感互补|
|**地下水**|well测网|区域性||必要，但覆盖有限，可用于验证|
||遥感|来源于全球重力测量，但空间分辨率低|年，低分辨率|测量的是TWSA，地下水需要进一步建模，粗分辨率使得不能直接使用，但是结合模型可用于研究|
||模型|区域到全球|年到几十年，有时近实时|较大不确定性，但是对与区域应用有用|
|**水质**|采样点|有限的空间覆盖|年，实时上受限|必要但是覆盖率差|
||遥感|全球|年，近实时|仅仅表面水变量，有的变量不确定性大|
||模型|取决于变量|年到几十年，近实时|有的变量不确定性较大|

接着，记录下具体的目前可用的遥感技术和产品。都在table3，这里也copy下，最后引用就不copy了，看原文。

|名称|发射和服役时间|空间分辨率|时间分辨率|
|-|-|-|-|
|**Precipitation**||||
|TMPA|2000-2018|0.25° 60°S to 60°N|3h|
|PERSIANN|2000-|0.25° 60°S to 60°N|1h
|CMORPH|2002-|0.07° 60°S to 60°N|30min|
|GSMAP|2005-|0.1°  global|1h|
|GPM/IMERG|2015-|0.1° 60°S to 60°N|30min|
|CHIRPS|1979-|0.05°|daily|
|MSWEP|1979-|0.1°|3h|
|**Land Surface Temperature(for ET)**|-|-|-|
|Landsat|2013(Landsat-8),2022(Landsat-9)|30(multisoectral)-100m(thermal)|16d|
|AVHRR|NOAA_19 2009发射，MetOp-B 2012发射|1km|1d|
|ASTER|2000|90m|16d|
|MODIS|2000|1km/6km|1d,8d|
|VIIRS|2011|375-750m|1d|
|Sentinel-3|2015/2017|1km|<2d|
|ECOSTRESS|2018,1y expected|38×69m|平均4天，focus区域亚日尺度|
|**ET Products**||||
|RS-PM|1983-2010|0.5°|daily|
|MOD16 ET|2000-2014|1km|8d|
|PT-JPL|1984-2006|1-0°|Monthly|
|GLEAM|1980-2016,2003-2015,2011-2015|0.25°|Daily|
|SSEBop|2003-|1km|10d|
|ALEXI-DisALEXI|Various regional data sets|30m(Landsat),1km(MODIS)|Hourly/daily|
|Global ESI|2001-|0.05°|4- and 12-week composites updated weekly|
|**Soil moisture**||||
|AMSR-E|2002-2011|25km|1d revisit|
|AMSR2|2012|25km|1d revisit|
|SMOS|2010|15,25,50km|1- to 3-day revisit; daily, 9-d and monthly|
|SMAP , SMAP L4 root zone soil moisture|36km,9km|1-3d revisit, 3h|
|Sentinel-1|2014/2016|<1km$^2$|8d|
|**Surface water height and extent**||||
|Jason-2/3(surface water height)|2008/2016|Lakes>100km$^2$|10d|
|Sentinel-3(surface water height)|2016|350m along track|27d|
|Landsat(surface water height)|2013(Landsat-8),2022(Landsat-9)|30(multisoectral)-100m(thermal)|16d|
|MODIS(surface water height)|2000-|500m|Daily|
|Sentinel-2(surface water height)|2015/2017|10-60m|5/10d|
|**Snow**||||
|MODIS SCE|2000-|500m, 0.05°|daily and 8d composite|
|VIIRS SCE|2012-|375m(swath),500m|daily and 8d composite|
|AMSR-E SWE|2000-2011|25km|daily, 5d, monthly|
|**Groundwater**||||
|GRACE|2002|500000km$^2$|30d|
|GRACE FO|2017|500000km$^2$|30d|
|**Vegetation**||||
|Landsat|2013(Landsat-8),2022(Landsat-9)|15m|16d|
|AVHRR/GIMMS|1979-2015|1km|7/14d composites|
|MODIS|2000|250m, 1km, 0.05°|16d,mongthly|
|VIIRS|2012|375m(swath),500m|daily and 8d composite|
|SPOT/PROBA-V|1990-2017|1km|10d|
|Sentinel-2|2015/2017|10-60m|5/10d|

剩下的先不管了，直接先试下GAGES-II里面流域的水库密度和水库库容等属性，把代码跑一下。
