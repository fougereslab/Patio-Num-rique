namespace PatioSim.Data.Contexts.PostgreSQL
{
    using Microsoft.EntityFrameworkCore;
    using Microsoft.AspNetCore.Http;
    using PatioSim.Data.Models;
    public class PatioContext : DbContext
    {
        public DbSet<Command> Commands { get; set; }
        public DbSet<Device> Devices { get; set; }
        public DbSet<DeviceCommand> DeviceCommands { get; set; }
        public DbSet<PredefinedCommand> PredefinedCommands { get; set; }
        public DbSet<Profile> Profiles { get; set; }

        private readonly IHttpContextAccessor _httpContextAccessor;

        public PatioContext(DbContextOptions<PatioContext> options) : base(options)
        { }

        public PatioContext()
        { }

        public PatioContext(DbContextOptions<PatioContext> options, IHttpContextAccessor httpContextAccessor)
            : base(options)
        {
            _httpContextAccessor = httpContextAccessor;
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            #region INDEXES
            #endregion INDEXES

            #region 1:N
            modelBuilder.Entity<DeviceCommand>().HasOne(dc => dc.Scenario).WithMany(b => b.DeviceCommands).HasForeignKey(dc => dc.ScenarioId);
            #endregion 1:N

            #region N:N

            modelBuilder.Entity<DeviceCommand>().HasKey(dc => new { dc.CommandId, dc.DeviceId });
            modelBuilder.Entity<DeviceCommand>().HasOne(dc => dc.Command).WithMany(b => b.DeviceCommands).HasForeignKey(dc => dc.CommandId);
            modelBuilder.Entity<DeviceCommand>().HasOne(dc => dc.Device).WithMany(b => b.DeviceCommands).HasForeignKey(dc => dc.DeviceId);

            #endregion N:N
        }
    }
}