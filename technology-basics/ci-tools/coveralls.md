# Coveralls 简介

Coveralls 是一个测试覆盖工具，有它能让看到代码的人对代码的质量有信心。这里记录一些简单的使用方法。主要参考资料有：

- [跟踪 Github 项目的持续集成状态](https://harttle.land/2016/04/30/github-ci.html)

首先，和 Travis CI一样需要去开通服务：https://coveralls.io/

但 Coveralls 不会直接运行测试，需要自己在测试完成后进行测试覆盖计算， 然后报告给Coveralls

而在python中，完成这一工作的一般用的是pytest。

和Travis CI结合的时候，在.travis.yml 文件里 指定pytest和coveralls到正确的位置上即可。

关键是pytest的设置。

后面逐步补充。