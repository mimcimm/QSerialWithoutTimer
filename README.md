# QSerialWithoutTimer
Bu uygumada Qtimer tetiklemesine alternatif yöntemler önerilmiştir,
Ek olarak istenilen işlemin tamamlandığını garanti eden bir QTimer kullanım önerisi sunulmuştur.

NOT: Uygulamadaki her Yordamı tek ek çalıştırarak deneyiniz.
   
    // 1.Yordam Önerisi
    - Bir timer oluturarak bu timerı sadece başlangıç ve bitirmede test yapabilmek için oluşturulmuştur, genel işleyişiyle bir alakası yoktur.
    - Döngüyü başlatmak için void EvtLoopTicker nesnesinin launch() methodunun 1 kere tetiklenmesi yeterlidir.
    - launch() methodu kendi içerisinde  tickNext(); 'i tetikleyerek  QMetaObject::invokeMethod(this, "tick", Qt::QueuedConnection); bağlantısını oluşturur.
    - invokeMethodu 2. parametreside aldığı methodu kendi nesnesi var olduğu sürece tetikler.
    
    // 2.Yordam Önerisi
    - Önce bir RenderEvent nesnesi oluşturulur.
    - Bu nesne constructure methodu içerisinde  update(); methdunu 1 kere çağırır.
    - Update methodu kendi içerisinde updateLater() methodunu çağırır
    - updateLater() içerisnde QCoreApplication::postEvent(this, new QEvent(QEvent::UpdateRequest)) tetiklenir.
    - post event periyordik olarak event(QEvent *event) nesnesini tetikler. 
    - event nesnesi içerisinde de update(); methodu çağırılarak döngüsel olarak tetiklenme sağlanır.
    
    // 3.Yordam Önerisi
    - QTimer kullanan fakat verilen taskı yaptığını garanti eden bir şekilde kurulmuştur.
    - FinishTask *ftask nesnesi oluşturup, bir kereye mahsus olmak üzere doJob(int); nesnesini çağırıyoruz.
    - Daha sonra bu method işini bitirdikten sonra tekrardan bir singleshot Qtimerla tekrardan tetilenir.
    - Her tetiklenmede işi yapmadan önce oluşturulan timer silinir. Bu sayede RAMde daima 1 adet timer yer kaplar.
    
    
    => 1. ve 2. yordam önerisinde tetiklenme süresini düşürmek için thread sleep edilir, farklı thread oluşturulup atansada sleep methodunun çağırılması ile tüm uygulama uyku moduna geçmektedir.
    => Uygulamayı tamamen uyutmanın önüne geçmek ve timer'ın tekrar tetiklenmeden önce görevinin tamamladığına emin olabilmek için 3. Yordam gönerilmiştir.
    

    
    
    
   

